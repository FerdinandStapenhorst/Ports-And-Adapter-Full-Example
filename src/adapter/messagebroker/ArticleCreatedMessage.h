#pragma once
#include "pch.h"
#include "Article.h"

class ArticleCreatedMessage {
	friend class ArticleMessageBroker;

public:
	ArticleCreatedMessage() noexcept = delete;
	ArticleCreatedMessage(const ArticleCreatedMessage& other) noexcept = delete;

private:
	ArticleCreatedMessage(ArticleCreatedMessage&& other) noexcept = default;//required
	ArticleCreatedMessage(ArticlePtr const article, String sentAt) : _Article{ article }, _SentAt{ sentAt } {}

	ArticlePtr _Article;
	String _SentAt;

public:
	static ArticleCreatedMessage Of(ArticlePtr const article);
	String ToString();
};
