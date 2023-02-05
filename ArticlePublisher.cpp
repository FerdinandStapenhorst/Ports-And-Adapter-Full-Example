#pragma once

#include "pch.h"
#include "ArticlePublisher.h"
#include "IArticleMessageSender.h"
#include "ISocialMediaPublisher.h"
#include "IAuthorNotifier.h"

ArticlePublisher::ArticlePublisher(IArticleMessageSenderPtr _MessageSender,
	std::vector<ISocialMediaPublisherPtr> _SocialMediaPublishers,
	std::vector<IAuthorNotifierPtr> _ArticleAuthorNotifiers) :
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