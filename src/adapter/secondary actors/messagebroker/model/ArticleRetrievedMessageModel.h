#pragma once
#include "pch.h"
#include "Article.h"

class ArticleRetrievedMessageModel {
	friend class ArticleMessageBroker;
public:
	ArticleRetrievedMessageModel(const ArticleRetrievedMessageModel& other) noexcept = default;
	DEFAULT_VIRTUAL_DESTRUCTOR(~ArticleRetrievedMessageModel)

private:
	ArticleRetrievedMessageModel(ArticleRetrievedMessageModel&& other) noexcept = default; //required

	ArticleRetrievedMessageModel(Article const& article, String const& sentAt);

	Article m_Article;
	String m_SentAt;

public:
	static ArticleRetrievedMessageModel Of(Article const& article);

	String ToString();
};
