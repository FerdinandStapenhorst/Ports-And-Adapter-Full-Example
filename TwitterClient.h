#pragma once
#include "pch.h"

class TwitterClient {
public:

	TwitterClient() noexcept = default;
	TwitterClient(const TwitterClient& other) noexcept = delete;
	TwitterClient(TwitterClient&& other) noexcept = delete;

public:
	void Tweet(ArticleTwitterModel const articleTweet);
};
