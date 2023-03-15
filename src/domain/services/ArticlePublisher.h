#pragma once
#include "pch.h"
#include "IArticlePublisherPort.h"
#include "IArticleMessageSenderPort.h"

class ArticlePublisher : public IArticlePublisherPort {
public:
	ArticlePublisher() noexcept = delete;
	ArticlePublisher(const ArticlePublisher& other) noexcept = delete;
	ArticlePublisher(ArticlePublisher&& other) noexcept = delete;
	DEFAULT_VIRTUAL_DESTRUCTOR(~ArticlePublisher)

	ArticlePublisher(IArticleMessageSenderPortPtr messageSender,
		std::vector<ISocialMediaPublisherPortPtr> socialMediaPublishers,
		std::vector<IAuthorNotifierPortPtr> articleAuthorNotifiers);

private:
	IArticleMessageSenderPortPtr m_MessageSender;
	std::vector<ISocialMediaPublisherPortPtr> m_SocialMediaPublishers;
	std::vector<IAuthorNotifierPortPtr> m_ArticleAuthorNotifiers;

public:

#pragma region IArticlePublisher

	void PublishCreationOf(Article const& article) const noexcept override final;
	void PublishRetrievalOf(Article const& article) const noexcept override final;

#pragma endregion
};
