#pragma once
#include "pch.h"
#include "Article.h"

class ArticleCreatedMessage {
	friend class MessageBrokerArticleMessageSender;

private:
	ArticleCreatedMessage() noexcept = default;
	ArticleCreatedMessage(const ArticleCreatedMessage& other) noexcept = default;
	ArticleCreatedMessage(ArticleCreatedMessage&& other) noexcept = default;
	virtual ~ArticleCreatedMessage() noexcept = default;
	ArticleCreatedMessage(ArticlePtr const article, String sentAt) : _Article{ article }, _SentAt{ sentAt } {}

	ArticlePtr _Article;
	String _SentAt;

public:
	static ArticleCreatedMessage Of(ArticlePtr const article);
	String ToString();
};
