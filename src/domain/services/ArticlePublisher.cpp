#pragma once

#include "pch.h"
#include "ArticlePublisher.h"
#include "IArticleMessageSender.h"
#include "ISocialMediaPublisher.h"
#include "IAuthorNotifier.h"

ArticlePublisher::ArticlePublisher(IArticleMessageSenderPortPtr messageSender,
	std::vector<ISocialMediaPublisherPortPtr> socialMediaPublishers,
	std::vector<IAuthorNotifierPortPtr> articleAuthorNotifiers) :
	m_MessageSender{ std::move(messageSender) },
	m_SocialMediaPublishers{ std::move(socialMediaPublishers) },
	m_ArticleAuthorNotifiers{ std::move(articleAuthorNotifiers) }
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