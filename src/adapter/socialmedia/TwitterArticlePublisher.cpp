#pragma once
#include "pch.h"
#include "TwitterArticlePublisher.h"
#include "TwitterClient.h"
#include "ArticleTwitterModel.h"

TwitterArticlePublisher::TwitterArticlePublisher(TwitterClientPtr const twitterClient) {
	_TwitterClient = twitterClient;
}

void TwitterArticlePublisher::Publish(ArticlePtr const article)
{
	ArticleTwitterModel articleTweet = ArticleTwitterModel::Of(article);
	_TwitterClient->Tweet(articleTweet);
}