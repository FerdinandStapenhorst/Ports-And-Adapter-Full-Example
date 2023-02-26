#pragma once
#include "pch.h"
#include "ArticleFacade.h"
#include "ArticleResponse.h"
#include "ArticleIdResponse.h"
#include "ArticleRequest.h"
#include "ArticleService.h"
#include "Article.h"

ArticleFacade::ArticleFacade(IArticleServicePtr articleService) :
	m_ArticleService{ articleService }
{}

ArticleResponse ArticleFacade::Get(String const& articleId) const noexcept
{
	ArticlePtr article = m_ArticleService->Get(articleId);
	return ArticleResponse::Of(article);
}

ArticleIdResponse ArticleFacade::Create(ArticleRequestPtr articleRequest) noexcept
{
	String articleId = m_ArticleService->Create(articleRequest->AuthorId(), articleRequest->Title(), articleRequest->Content());
	return ArticleIdResponse::Of(articleId);
}