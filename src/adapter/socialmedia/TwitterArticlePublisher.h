#pragma once
#include "pch.h"
#include "ISocialMediaPublisher.h"

class TwitterArticlePublisher : public ISocialMediaPublisher {
public:
	TwitterArticlePublisher() noexcept = delete;
	TwitterArticlePublisher(const TwitterArticlePublisher& other) noexcept = delete;
	TwitterArticlePublisher(TwitterArticlePublisher&& other) noexcept = delete;

	TwitterArticlePublisher(TwitterClientPtr const twitterClient);

private:
	TwitterClientPtr _TwitterClient;

	virtual void Publish(ArticlePtr const article) override;
};
