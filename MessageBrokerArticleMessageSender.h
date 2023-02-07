#pragma once
#include "pch.h"
#include "IArticleMessageSender.h"
#include "Article.h"

class MessageBrokerArticleMessageSender : public IArticleMessageSender {
public:
	MessageBrokerArticleMessageSender() noexcept = default; //required
	MessageBrokerArticleMessageSender(const MessageBrokerArticleMessageSender& other) noexcept = delete;
	MessageBrokerArticleMessageSender(MessageBrokerArticleMessageSender&& other) noexcept = delete;

public:
	virtual void SendMessageForCreated(ArticlePtr const article) override;
	virtual void SendMessageForRetrieved(ArticlePtr const article)  override;
};
