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

ArticlePublisherPtr CreateArticlePublisher()
{
	//TwitterClient
	TwitterClientPtr twitterClient = CreateInstance(new TwitterClient);

	//Social Media Publisher
	ISocialMediaPublisherPortPtr socialMediaPublisher = CreateInstance(new TwitterArticlePublisher(twitterClient));
	std::vector<ISocialMediaPublisherPortPtr> socialMediaPublisherList;
	socialMediaPublisherList.push_back(socialMediaPublisher);

	//Author SMS notifier
	IAuthorNotifierPortPtr authorSmSNotifier = CreateInstance(new AuthorSmsNotifier);

	//Author E-Mail notifier list
	IAuthorNotifierPortPtr authorMailNotifier = CreateInstance(new AuthorMailNotifier);
	std::vector<IAuthorNotifierPortPtr> authorMailNotifierList;
	authorMailNotifierList.push_back(authorSmSNotifier);
	authorMailNotifierList.push_back(authorMailNotifier);

	//MessageSender
	IArticleMessageSenderPortPtr articleMessageSender = CreateInstance(new ArticleMessageBroker);

	//Article Publisher
	return CreateInstance(new ArticlePublisher(articleMessageSender, socialMediaPublisherList, authorMailNotifierList));
}

ArticleServicePtr CreateArticleService() {
	//Article repo
	IArticleRepositoryPortPtr articleRepo = CreateInstance(new DbArticleRepository);
	//Author Repo
	IAuthorRepositoryPortPtr authorRepo = CreateInstance(new AuthorRepository);
	//Article Service
	return  CreateInstance(new ArticleService(articleRepo, authorRepo, CreateArticlePublisher()));
}

ArticleEndpointPtr CreateArticleEndpoint()
{
	ArticleFacadePtr articleFacade = CreateInstance(new ArticleFacade(CreateArticleService()));
	return CreateInstance(new ArticleEndpoint(articleFacade));
}

int main()
{
	//Simulate incoming request from endpoint to get an article
	ArticleEndpointPtr articleEndpoint = CreateArticleEndpoint();
	ArticleResponse article = articleEndpoint->Get("*");


	auto author = Author::Create()
		.withId("2")
		.withName(article.AuthorName())
		.build();

	//Create a new article
	auto articleNew = Article::Create()
		.withAuthor(author)
		.withTitle(article.Title())
		.withId(article.Id())
		.withContent(article.Content())
		.build();
	//Create request
	ArticleRequestPtr articleRequest = CreateInstance(new ArticleRequest(articleNew));

	//simulate sending requerst to endpoint to create a new article 
	auto articleIdResponse = articleEndpoint->Create(articleRequest);

	return 0;
}