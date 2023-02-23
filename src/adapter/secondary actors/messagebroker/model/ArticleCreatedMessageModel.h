#pragma once
#include "pch.h"
#include "Article.h"

class ArticleCreatedMessageModel {
	friend class ArticleMessageBroker;

public:
	ArticleCreatedMessageModel(const ArticleCreatedMessageModel& other) noexcept = delete;

private:
	ArticleCreatedMessageModel(ArticleCreatedMessageModel&& other) noexcept = default;//required
	ArticleCreatedMessageModel(ArticlePtr const article, String sentAt) : _Article{ article }, _SentAt{ sentAt } {}

	ArticlePtr _Article;
	String _SentAt;

public:
	static ArticleCreatedMessageModel Of(ArticlePtr const article);
	String ToString();
};
