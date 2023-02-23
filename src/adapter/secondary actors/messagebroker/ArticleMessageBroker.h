#pragma once
#include "pch.h"
#include "IArticleMessageSenderPort.h"
#include "Article.h"

class ArticleMessageBroker : public IArticleMessageSenderPort {
public:
	ArticleMessageBroker() noexcept = default; //required
	ArticleMessageBroker(const ArticleMessageBroker& other) noexcept = delete;

public:
	void SendMessageForCreated(ArticlePtr const article) override;
	void SendMessageForRetrieved(ArticlePtr const article) override;
};
