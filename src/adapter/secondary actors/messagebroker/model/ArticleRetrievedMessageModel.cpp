#pragma once

#include "pch.h"
#include "ArticleRetrievedMessageModel.h"

ArticleRetrievedMessageModel::ArticleRetrievedMessageModel(Article const& article, String const& sentAt) :
	m_Article{ article },
	m_SentAt{ sentAt }
{}

ArticleRetrievedMessageModel ArticleRetrievedMessageModel::Of(Article const& article)
{
	ArticleRetrievedMessageModel a(article, "Now");
	return a;
}

String ArticleRetrievedMessageModel::ToString()
{
	return std::format("Article >>{}<< retrieved", m_Article.Title());
}