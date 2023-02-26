#pragma once
#include "pch.h"
#include "ArticleSmsModel.h"
#include "Article.h"
#include "Author.h"

ArticleSmsModel::ArticleSmsModel(String const& recipientId, String const& text) :
	m_RecipientId{ recipientId },
	m_Text{ text }
{}

ArticleSmsModel ArticleSmsModel::Of(Article const& article)
{
	ArticleSmsModel a(article.GetAuthor().Name(),
		std::format(CONTENT, article.Title()));
	return a;
}

String ArticleSmsModel::ToString()
{
	return m_Text;
}