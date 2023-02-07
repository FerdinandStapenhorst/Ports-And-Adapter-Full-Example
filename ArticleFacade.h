#pragma once
#include "pch.h"

class ArticleFacade {
public:
	ArticleFacade() noexcept = delete;
	ArticleFacade(const ArticleFacade& other) noexcept = delete;
	ArticleFacade(ArticleFacade&& other) noexcept = delete;

	ArticleFacade(ArticleServicePtr const articleService);

private:
	ArticleServicePtr _ArticleService;

public:
	ArticleResponse Get(String const& articleId);
	ArticleIdResponse Create(ArticleRequestPtr articleRequest);
};
