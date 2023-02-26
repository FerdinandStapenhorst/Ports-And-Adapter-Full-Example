#pragma once
#include "pch.h"
#include "ITwitterClient.h"

class TwitterClient : public ITwitterClient {
public:

	TwitterClient() noexcept = default;
	TwitterClient(const TwitterClient& other) noexcept = delete;
	TwitterClient(TwitterClient&& other) noexcept = delete;
	virtual ~TwitterClient() = default;

public:
	virtual void Tweet(ArticleTwitterModel const articleTweet) const noexcept override final;
};
