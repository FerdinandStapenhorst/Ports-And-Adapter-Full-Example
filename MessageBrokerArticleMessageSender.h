#pragma once
#include "pch.h"
#include "IArticleMessageSender.h"
#include "Article.h"

class MessageBrokerArticleMessageSender : public IArticleMessageSender {
private:
	MessageBrokerArticleMessageSender() noexcept = delete;
	MessageBrokerArticleMessageSender(const MessageBrokerArticleMessageSender& other) noexcept = default;
	MessageBrokerArticleMessageSender(MessageBrokerArticleMessageSender&& other) noexcept = default;
	virtual ~MessageBrokerArticleMessageSender() noexcept = default;

public:
	virtual void SendMessageForCreated(ArticlePtr const article) override;
	virtual void SendMessageForRetrieved(ArticlePtr const article)  override;
};
