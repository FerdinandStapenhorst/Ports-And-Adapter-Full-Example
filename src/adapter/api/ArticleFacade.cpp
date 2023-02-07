#pragma once
#include "pch.h"
#include "ArticleFacade.h"
#include "ArticleResponse.h"
#include "ArticleIdResponse.h"
#include "ArticleRequest.h"
#include "ArticleService.h"
#include "Article.h"

ArticleFacade::ArticleFacade(ArticleServicePtr const articleService) :
	_ArticleService{ articleService }
{}

ArticleResponse ArticleFacade::Get(String const& articleId)
{
	std::cout << "ArticleFacade -> Get called" << std::endl;
	ArticlePtr article = _ArticleService->Get(articleId);
	return ArticleResponse::Of(article);
}

ArticleIdResponse ArticleFacade::Create(ArticleRequestPtr articleRequest)
{
	std::cout << "ArticleFacade -> Create called" << std::endl;
	String articleId = _ArticleService->Create(articleRequest->AuthorId(), articleRequest->Title(), articleRequest->Content());
	return ArticleIdResponse::Of(articleId);
}