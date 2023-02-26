#pragma once
#include "pch.h"
#include "ITwitterClient.h"

class TwitterClient : public ITwitterClient {
public:

	TwitterClient() noexcept = default;
	TwitterClient(const TwitterClient& other) noexcept = delete;
	TwitterClient(TwitterClient&& other) noexcept = default;

	virtual ~TwitterClient() {
		std::cout << "~TwitterClient" << std::endl;
	}

public:
	virtual void Tweet(ArticleTwitterModel const articleTweet) const noexcept override final;
};
