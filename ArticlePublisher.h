#pragma once
#include "pch.h"


class ArticlePublisher {
public:
	ArticlePublisher() noexcept = default;
	ArticlePublisher(const ArticlePublisher& other) noexcept = default;
	ArticlePublisher(ArticlePublisher&& other) noexcept = default;
	virtual ~ArticlePublisher() noexcept = default;

private:

	IArticleMessageSenderPtr _MessageSender;
	std::vector<ISocialMediaPublisherPtr> _SocialMediaPublishers;
	std::vector<IAuthorNotifierPtr> _ArticleAuthorNotifiers;

public:
	ArticlePublisher(IArticleMessageSenderPtr _MessageSender,
		std::vector<ISocialMediaPublisherPtr> _SocialMediaPublishers,
		std::vector<IAuthorNotifierPtr> _ArticleAuthorNotifiers);

	void PublishCreationOf(ArticlePtr const article);

	void PublishRetrievalOf(ArticlePtr const article);
};
