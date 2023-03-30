#pragma once
// ***************************************************************************
// ********************** Ports & Andapter example ***************************
// *                                                                         *
// * - Primary Adapters get the inbound port's interface injected and use it *
// * - Secondary Adapters implement (inherit) the outbound port's interface  *
// ***************************************************************************

#include "pch.h"
#include "DbArticleRepository.h"
#include "AuthorRepository.h"
#include "ArticleMessageBroker.h"
#include "TwitterArticlePublisher.h"
#include "AuthorSmsNotifier.h"
#include "AuthorMailNotifier.h"
#include "TwitterClient.h"
#include "ArticlePublisher.h"
#include "ArticleFacade.h"
#include "ArticleEndpoint.h"
#include "ArticleRequest.h"
#include "ArticleIdResponse.h"
#include "ArticleResponse.h"

IArticlePublisherPortPtr CreateArticlePublisher()
{
	//TwitterClient
	ITwitterClientPtr twitterClient = CreateUniqueInstance(new TwitterClient);

	//Social Media Publisher
	ISocialMediaPublisherPortPtr socialMediaPublisher = CreateUniqueInstance(new TwitterArticlePublisher(std::move(twitterClient)));
	std::vector<ISocialMediaPublisherPortPtr> socialMediaPublisherList;
	socialMediaPublisherList.push_back(std::move(socialMediaPublisher));

	//Author SMS notifier
	IAuthorNotifierPortPtr authorSmSNotifier = CreateUniqueInstance(new AuthorSmsNotifier);

	//Author E-Mail notifier list
	IAuthorNotifierPortPtr authorMailNotifier = CreateUniqueInstance(new AuthorMailNotifier);
	std::vector<IAuthorNotifierPortPtr> authorMailNotifierList;
	authorMailNotifierList.push_back(std::move(authorSmSNotifier));
	authorMailNotifierList.push_back(std::move(authorMailNotifier));

	//MessageSender
	IArticleMessageSenderPortPtr articleMessageSender = CreateUniqueInstance(new ArticleMessageBroker);

	//Article Publisher
	return (CreateUniqueInstance(new ArticlePublisher(std::move(articleMessageSender), std::move(socialMediaPublisherList), std::move(authorMailNotifierList))));
}

IArticleServicePortPtr CreateArticleService() {
	//Article repo
	IArticleRepositoryPortPtr articleRepo = CreateUniqueInstance(new DbArticleRepository);
	//Author Repo
	IAuthorRepositoryPortPtr authorRepo = CreateUniqueInstance(new AuthorRepository);
	//Article Service
	IArticlePublisherPortPtr articlePublisher = CreateArticlePublisher();
	return CreateUniqueInstance(new ArticleService(std::move(articleRepo), std::move(authorRepo), std::move(articlePublisher)));
}

IArticleEndpointPtr CreateArticleEndpoint()
{
	IArticleServicePortPtr ArticleService = CreateArticleService();
	IArticleFacadePtr articleFacade = CreateUniqueInstance(new ArticleFacade(std::move(ArticleService)));
	return CreateUniqueInstance(new ArticleEndpoint(std::move(articleFacade)));
}

int main()
{
	//Simulate incoming request from endpoint to get an article
	IArticleEndpointPtr articleEndpoint = CreateArticleEndpoint();

	//Get article from database
	ArticleResponse article = articleEndpoint->Get("0815");

	
	LOGSTRING(std::format("Article loaded.\n  Autor:   {}\n  ID:      {}\n  Title:   {}\n  Content:   {}",
	 article.AuthorName(), article.Id(), article.Title(), article.Content()))

	//Create author
	LOGSTRING("Creating new author...")
	auto author = Author::Create()
		.withId("2")
		.withName(article.AuthorName())
		.build();

	//Create a new article
	LOGSTRING("Creating new article for author...")
	auto articleNew = Article::Create()
		.withAuthor(*author)
		.withTitle(article.Title())
		.withId(article.Id())
		.withContent(article.Content())
		.build();

	//Simulating create request
	ArticleRequestPtr articleRequest = CreateUniqueInstance(new ArticleRequest(std::move(articleNew)));

	{
		//simulate sending requerst to endpoint to create a new article
		auto articleIdResponse = articleEndpoint->Create(std::move(articleRequest));
	}

	return 0;
}