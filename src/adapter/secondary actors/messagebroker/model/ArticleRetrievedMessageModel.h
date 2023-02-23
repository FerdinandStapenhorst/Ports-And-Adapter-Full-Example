#pragma once
#include "pch.h"
#include "Article.h"

class ArticleRetrievedMessageModel {
	friend class ArticleMessageBroker;
public:
	ArticleRetrievedMessageModel(const ArticleRetrievedMessageModel& other) noexcept = delete;

private:
	ArticleRetrievedMessageModel(ArticleRetrievedMessageModel&& other) noexcept = default; //required

	ArticleRetrievedMessageModel(ArticlePtr const article, String const& sentAt);

	ArticlePtr _Article;
	String _SentAt;

public:
	static ArticleRetrievedMessageModel Of(ArticlePtr const article);

	String ToString();
};
