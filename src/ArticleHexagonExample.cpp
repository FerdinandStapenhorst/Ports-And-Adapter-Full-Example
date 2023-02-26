#pragma once
// ************************************************
// *********   Ports & Andapter example ***********
// ************************************************

#include "pch.h"
#include "Author.h"
#include "Article.h"
#include "DbArticleRepository.h"
#include "AuthorRepository.h"
#include "ArticleMessageBroker.h"
#include "TwitterArticlePublisher.h"
#include "AuthorSmsNotifier.h"
#include "AuthorMailNotifier.h"
#include "TwitterClient.h"
#include "ArticlePublisher.h"
#include "ArticleFacade.h"
#include "ArticleService.h"
#include "ArticleEndpoint.h"
#include "ArticleRequest.h"
#include "ArticleIdResponse.h"
#include "ArticleResponse.h"

IArticlePublisherPtr CreateArticlePublisher()
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

IArticleServicePtr CreateArticleService() {
	//Article repo
	IArticleRepositoryPortPtr articleRepo = CreateUniqueInstance(new DbArticleRepository);
	//Author Repo
	IAuthorRepositoryPortPtr authorRepo = CreateUniqueInstance(new AuthorRepository);
	//Article Service
	IArticlePublisherPtr articlePublisher = CreateArticlePublisher();
	return CreateUniqueInstance(new ArticleService(std::move(articleRepo), std::move(authorRepo), std::move(articlePublisher)));
}

IArticleEndpointPtr CreateArticleEndpoint()
{
	IArticleServicePtr ArticleService = CreateArticleService();
	IArticleFacadePtr articleFacade = CreateUniqueInstance(new ArticleFacade(std::move(ArticleService)));
	return CreateUniqueInstance(new ArticleEndpoint(std::move(articleFacade)));
}

int main()
{
	//Simulate incoming request from endpoint to get an article
	IArticleEndpointPtr articleEndpoint = CreateArticleEndpoint();

	ArticleResponse article = articleEndpoint->Get("*");

	auto author = Author::Create()
		.withId("2")
		.withName(article.AuthorName())
		.build();

	//Create a new article
	auto articleNew = Article::Create()
		.withAuthor(*author)
		.withTitle(article.Title())
		.withId(article.Id())
		.withContent(article.Content())
		.build();

	//Create request
	ArticleRequestPtr articleRequest = CreateUniqueInstance(new ArticleRequest(std::move(articleNew)));

	//simulate sending requerst to endpoint to create a new article
	auto articleIdResponse = articleEndpoint->Create(std::move(articleRequest));

	return 0;
}