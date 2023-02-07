#pragma once
#include "pch.h"
#include "Article.h"

class ArticleRetrievedMessage {
	friend class MessageBrokerArticleMessageSender;
public:
	ArticleRetrievedMessage() noexcept = delete;
	ArticleRetrievedMessage(const ArticleRetrievedMessage& other) noexcept = delete;

private:
	ArticleRetrievedMessage(ArticleRetrievedMessage&& other) noexcept = default; //required

	ArticleRetrievedMessage(ArticlePtr const article, String const& sentAt);

	ArticlePtr _Article;
	String _SentAt;

public:
	static ArticleRetrievedMessage Of(ArticlePtr const article);

	String ToString();
};
