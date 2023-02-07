#pragma once
#include "pch.h"

class ArticlePublisher {
public:
	ArticlePublisher() noexcept = delete;
	ArticlePublisher(const ArticlePublisher& other) noexcept = delete;
	ArticlePublisher(ArticlePublisher&& other) noexcept = delete;

	ArticlePublisher(IArticleMessageSenderPtr _MessageSender,
		std::vector<ISocialMediaPublisherPtr> _SocialMediaPublishers,
		std::vector<IAuthorNotifierPtr> _ArticleAuthorNotifiers);

private:
	IArticleMessageSenderPtr _MessageSender;
	std::vector<ISocialMediaPublisherPtr> _SocialMediaPublishers;
	std::vector<IAuthorNotifierPtr> _ArticleAuthorNotifiers;

public:
	void PublishCreationOf(ArticlePtr const article);

	void PublishRetrievalOf(ArticlePtr const article);
};
