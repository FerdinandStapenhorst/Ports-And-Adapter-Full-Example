#pragma once

#include "pch.h"
#include "ArticlePublisher.h"
#include "IArticleMessageSenderPort.h"
#include "ISocialMediaPublisherPort.h"
#include "IAuthorNotifierPort.h"

ArticlePublisher::ArticlePublisher(IArticleMessageSenderPortPtr _MessageSender,
	std::vector<ISocialMediaPublisherPortPtr> _SocialMediaPublishers,
	std::vector<IAuthorNotifierPortPtr> _ArticleAuthorNotifiers) :
	m_MessageSender{ _MessageSender },
	m_SocialMediaPublishers{ _SocialMediaPublishers },
	m_ArticleAuthorNotifiers{ _ArticleAuthorNotifiers }
{
}

void ArticlePublisher::PublishCreationOf(Article const& article) const noexcept
{
	m_MessageSender->SendMessageForCreated(article);

	for (auto const& item : m_SocialMediaPublishers) {
		item->Publish(article);
	}
	for (auto const& item : m_ArticleAuthorNotifiers) {
		item->NotifyAboutCreationOf(article);
	}
}

void ArticlePublisher::PublishRetrievalOf(Article const& article) const noexcept
{
	m_MessageSender->SendMessageForRetrieved(article);
}