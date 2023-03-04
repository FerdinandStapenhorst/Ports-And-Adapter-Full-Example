#pragma once
#include "pch.h"
#include "TwitterClient.h"
#include "ArticleTwitterModel.h"

void TwitterClient::Tweet(ArticleTwitterModel const articleTweet) const noexcept
{
	/**
	 * social media integration implementation comes here
	 */
	LOGSTRING(std::format("Publishing Tweet: {}", articleTweet.ToString()))
}