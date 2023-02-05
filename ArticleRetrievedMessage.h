#pragma once
#include "pch.h"
#include "Article.h"

class ArticleRetrievedMessage {
	friend class MessageBrokerArticleMessageSender;

private:
	ArticleRetrievedMessage() noexcept = default;
	ArticleRetrievedMessage(const ArticleRetrievedMessage& other) noexcept = default;
	ArticleRetrievedMessage(ArticleRetrievedMessage&& other) noexcept = default;
	virtual ~ArticleRetrievedMessage() noexcept = default;
	ArticleRetrievedMessage(ArticlePtr const article, String const& sentAt);

	ArticlePtr _Article;
	String _SentAt;

public:
	static ArticleRetrievedMessage Of(ArticlePtr const article);

	String ToString();
};
