#pragma once
#include "pch.h"
#include "ISocialMediaPublisherPort.h"

class TwitterArticlePublisher : public ISocialMediaPublisherPort {
public:
	TwitterArticlePublisher(const TwitterArticlePublisher& other) noexcept = delete;
	TwitterArticlePublisher(TwitterClientPtr const twitterClient);

private:
	TwitterClientPtr _TwitterClient;

	virtual void Publish(ArticlePtr const article) override;
};
