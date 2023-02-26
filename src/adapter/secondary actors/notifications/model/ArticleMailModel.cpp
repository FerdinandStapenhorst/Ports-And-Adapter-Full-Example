#pragma once
#include "pch.h"
#include "ArticleMailModel.h"
#include "Article.h"
#include "Author.h"

ArticleMailModel::ArticleMailModel(String const& recipientId, String const& subject, String const& content) :
	m_RecipientId{ recipientId },
	m_Subject{ subject },
	m_Content{ content }
{}

ArticleMailModel ArticleMailModel::Of(Article const& article)
{
	ArticleMailModel a(article.GetAuthor().Name(),
		std::format(SUBJECT, article.Title()),
		std::format(CONTENT, article.Content()));
	return a;
}

String ArticleMailModel::ToString()
{
	return m_Subject;
}