#pragma once

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
	ISocialMediaPublisherPtr socialMediaPublisher = CreateInstance(new TwitterArticlePublisher(twitterClient));
	std::vector<ISocialMediaPublisherPtr> socialMediaPublisherList;
	socialMediaPublisherList.push_back(socialMediaPublisher);

	//Author SMS notifier
	IAuthorNotifierPtr authorSmSNotifier = CreateInstance(new AuthorSmsNotifier);

	//Author E-Mail notifier list
	IAuthorNotifierPtr authorMailNotifier = CreateInstance(new AuthorMailNotifier);
	std::vector<IAuthorNotifierPtr> authorMailNotifierList;
	authorMailNotifierList.push_back(authorSmSNotifier);
	authorMailNotifierList.push_back(authorMailNotifier);

	//MessageSender
	IArticleMessageSenderPtr articleMessageSender = CreateInstance(new ArticleMessageBroker);

	//Article Publisher
	return CreateInstance(new ArticlePublisher(articleMessageSender, socialMediaPublisherList, authorMailNotifierList));
}

ArticleServicePtr CreateArticleService() {
	//Article repo
	IArticleRepositoryPtr articleRepo = CreateInstance(new DbArticleRepository);
	//Author Repo
	IAuthorRepositoryPtr authorRepo = CreateInstance(new AuthorRepository);
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
	ArticleEndpointPtr articleEndpoint = CreateArticleEndpoint();
	ArticleResponse article = articleEndpoint->Get("*");


	auto author = Author::Create()
		.withId("2")
		.withName(article.AuthorName())
		.build();

	auto articleNew = Article::Create()
		.withAuthor(author)
		.withTitle(article.Title())
		.withId(article.Id())
		.withContent(article.Content())
		.build();

	ArticleRequestPtr articleRequest = CreateInstance(new ArticleRequest(articleNew));

	//Create a new article
	auto articleIdResponse = articleEndpoint->Create(articleRequest);

	return 0;
}