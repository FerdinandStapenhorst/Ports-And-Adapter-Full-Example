#pragma once
#include "pch.h"
#include "Article.h"

class ArticleCreatedMessageModel {
	friend class ArticleMessageBroker;

public:
	ArticleCreatedMessageModel(const ArticleCreatedMessageModel& other) noexcept = default;
	DEFAULT_VIRTUAL_DESTRUCTOR(~ArticleCreatedMessageModel)
	

private:
	ArticleCreatedMessageModel(ArticleCreatedMessageModel&& other) noexcept = default;//required
	ArticleCreatedMessageModel(Article const& article, String sentAt) : m_Article{ article }, m_SentAt{ sentAt } {}

	Article m_Article;
	String m_SentAt;

public:
	static ArticleCreatedMessageModel Of(Article const& article);
	String ToString();
};
