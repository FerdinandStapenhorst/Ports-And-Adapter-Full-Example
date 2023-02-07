#pragma once
#include "pch.h"
#include "IArticleMessageSender.h"
#include "Article.h"

class ArticleMessageBroker : public IArticleMessageSender {
public:
	ArticleMessageBroker() noexcept = default; //required
	ArticleMessageBroker(const ArticleMessageBroker& other) noexcept = delete;
	ArticleMessageBroker(ArticleMessageBroker&& other) noexcept = delete;

public:
	virtual void SendMessageForCreated(ArticlePtr const article) override;
	virtual void SendMessageForRetrieved(ArticlePtr const article)  override;
};
