#pragma once
#include "pch.h"
#include "TwitterArticlePublisher.h"
#include "TwitterClient.h"
#include "ArticleTwitterModel.h"

TwitterArticlePublisher::TwitterArticlePublisher(ITwitterClientPtr twitterClient) : 
	_TwitterClient(std::move(twitterClient)) 
{
}

void TwitterArticlePublisher::Publish(Article const & article) const noexcept
{
	ArticleTwitterModel articleTweet = ArticleTwitterModel::Of(article);
	_TwitterClient->Tweet(articleTweet);
}