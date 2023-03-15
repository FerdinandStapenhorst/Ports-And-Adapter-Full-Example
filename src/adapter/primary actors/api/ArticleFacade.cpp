#pragma once
#include "pch.h"
#include "ArticleFacade.h"
#include "ArticleResponse.h"
#include "ArticleIdResponse.h"
#include "ArticleRequest.h"
#include "ArticleService.h"
#include "Article.h"

ArticleFacade::ArticleFacade(IArticleServicePortPtr articleService) :
	m_ArticleService{ std::move(articleService) }
{
	LOGSTRING_CTOR(ArticleFacade)
}

ArticleResponse ArticleFacade::Get(String const& articleId) const noexcept
{
	LOGSTRING("ArticleFacade -> Get called")
	ArticlePtr article = m_ArticleService->Get(articleId);
	return ArticleResponse::Of(std::move(article));
}

ArticleIdResponse ArticleFacade::Create(ArticleRequestPtr articleRequest) noexcept
{
	LOGSTRING("ArticleFacade -> Create called")
	String articleId = m_ArticleService->Create(articleRequest->AuthorId(), articleRequest->Title(), articleRequest->Content());
	return ArticleIdResponse::Of(articleId);
}