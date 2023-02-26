#include "pch.h"
#include "ArticleCreatedMessageModel.h"

ArticleCreatedMessageModel ArticleCreatedMessageModel::Of(Article const& article)
{
	ArticleCreatedMessageModel a(article, "Now");
	return a;
}

String ArticleCreatedMessageModel::ToString()
{
	return std::format("Article >>{}<< retrieved", m_Article.Title());
}