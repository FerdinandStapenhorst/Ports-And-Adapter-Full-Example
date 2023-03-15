#pragma once
#include "pch.h"
#include "ISocialMediaPublisherPort.h"

class TwitterArticlePublisher : public ISocialMediaPublisherPort {  //Implement (inherit) the required port
public:
	TwitterArticlePublisher() noexcept = delete;
	TwitterArticlePublisher(const TwitterArticlePublisher& other) noexcept = delete;
	TwitterArticlePublisher(TwitterArticlePublisher&& other) noexcept = delete;
	TwitterArticlePublisher(ITwitterClientPtr twitterClient);

	DEFAULT_VIRTUAL_DESTRUCTOR(~TwitterArticlePublisher)

private:
	ITwitterClientPtr _TwitterClient;

	#pragma region ISocialMediaPublisherPort

	void Publish(Article const& article) const noexcept override final;

	#pragma endregion

};
