#include "pch.h"
#include "ArticleEndpoint.h"
#include "ArticleFacade.h"
#include "Article.h"
#include "ArticleIdResponse.h"
#include "ArticleResponse.h"
#include "ArticleRequest.h"

ArticleEndpoint::ArticleEndpoint(IArticleFacadePtr articles) :
	m_Articles{ std::move(articles) }
{
	LOGSTRING_CTOR(ArticleEndpoint)
}

ArticleResponse ArticleEndpoint::Get(String const& articleId) const noexcept
{
	LOGSTRING("ArticleEndpoint->Get called")
	return m_Articles->Get(articleId);
}

ArticleIdResponse ArticleEndpoint::Create(ArticleRequestPtr articleRequest) noexcept
{
	LOGSTRING("ArticleEndpoint->Create called")
	return m_Articles->Create(std::move(articleRequest));
}