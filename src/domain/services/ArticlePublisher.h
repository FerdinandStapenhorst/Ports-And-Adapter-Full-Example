#pragma once
#include "pch.h"

class ArticlePublisher {
public:
	ArticlePublisher() noexcept = delete;
	ArticlePublisher(const ArticlePublisher& other) noexcept = delete;
	ArticlePublisher(ArticlePublisher&& other) noexcept = delete;

	ArticlePublisher(IArticleMessageSenderPortPtr _MessageSender,
		std::vector<ISocialMediaPublisherPortPtr> _SocialMediaPublishers,
		std::vector<IAuthorNotifierPortPtr> _ArticleAuthorNotifiers);

private:
	IArticleMessageSenderPortPtr _MessageSender;
	std::vector<ISocialMediaPublisherPortPtr> _SocialMediaPublishers;
	std::vector<IAuthorNotifierPortPtr> _ArticleAuthorNotifiers;

public:
	void PublishCreationOf(ArticlePtr const article);

	void PublishRetrievalOf(ArticlePtr const article);
};
