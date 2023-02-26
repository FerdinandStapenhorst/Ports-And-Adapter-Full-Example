#pragma once
#include "pch.h"
#include "ArticleIdResponse.h"

ArticleIdResponse::ArticleIdResponse(String const& id) : m_Id{ id } {}

ArticleIdResponse ArticleIdResponse::Of(String const& articleId)
{
	ArticleIdResponse a(articleId);
	return a;
}

String ArticleIdResponse::Id() const
{
	return m_Id;
}