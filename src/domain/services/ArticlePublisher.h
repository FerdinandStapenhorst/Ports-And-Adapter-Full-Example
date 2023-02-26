#pragma once
#include "pch.h"
#include "IArticlePublisher.h"
#include "IArticleMessageSenderPort.h"

class ArticlePublisher : public IArticlePublisher {
public:
	ArticlePublisher() noexcept = delete;
	ArticlePublisher(const ArticlePublisher& other) noexcept = delete;
	ArticlePublisher(ArticlePublisher&& other) noexcept = delete;
	virtual ~ArticlePublisher() {
		std::cout << "~ArticlePublisher" << std::endl;
	}

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
