#pragma once
#include "pch.h"
#include "TwitterClient.h"
#include "ArticleTwitterModel.h"

void TwitterClient::Tweet(ArticleTwitterModel const articleTweet)
{
	/**
	 * social media integration implementation comes here
	 */
	std::cout << "Publishing Tweet: " << articleTweet.ToString() << std::endl;
}