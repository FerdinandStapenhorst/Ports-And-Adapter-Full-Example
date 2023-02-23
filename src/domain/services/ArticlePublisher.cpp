#pragma once

#include "pch.h"
#include "ArticlePublisher.h"
#include "IArticleMessageSenderPort.h"
#include "ISocialMediaPublisherPort.h"
#include "IAuthorNotifierPort.h"

ArticlePublisher::ArticlePublisher(IArticleMessageSenderPortPtr _MessageSender,
	std::vector<ISocialMediaPublisherPortPtr> _SocialMediaPublishers,
	std::vector<IAuthorNotifierPortPtr> _ArticleAuthorNotifiers) :
	_MessageSender{ _MessageSender },
	_SocialMediaPublishers{ _SocialMediaPublishers },
	_ArticleAuthorNotifiers{ _ArticleAuthorNotifiers }
{
}

void ArticlePublisher::PublishCreationOf(ArticlePtr const article)
{
	_MessageSender->SendMessageForCreated(article);

	for (auto const& item : _SocialMediaPublishers) {
		item->Publish(article);
	}
	for (auto const& item : _ArticleAuthorNotifiers) {
		item->NotifyAboutCreationOf(article);
	}
}

void ArticlePublisher::PublishRetrievalOf(ArticlePtr const article)
{
	_MessageSender->SendMessageForRetrieved(article);
}