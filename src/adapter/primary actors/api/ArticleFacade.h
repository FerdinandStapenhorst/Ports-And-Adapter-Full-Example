#pragma once
#include "pch.h"
//Facade design pattern: https://refactoring.guru/design-patterns/facade
class ArticleFacade {
public:
	ArticleFacade(const ArticleFacade& other) noexcept = delete;
	ArticleFacade(ArticleServicePtr const articleService);

private:
	ArticleServicePtr _ArticleService;

public:
	ArticleResponse Get(String const& articleId);
	ArticleIdResponse Create(ArticleRequestPtr articleRequest);
};
