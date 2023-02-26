#pragma once
#include "pch.h"
#include "IArticleFacade.h"

//Facade design pattern: https://refactoring.guru/design-patterns/facade
class ArticleFacade : public IArticleFacade {
public:
	ArticleFacade(const ArticleFacade& other) noexcept = delete;
	ArticleFacade(IArticleServicePtr const articleService);
	virtual ~ArticleFacade() = default;

private:
	IArticleServicePtr m_ArticleService;

public:
	ArticleResponse Get(String const& articleId) const noexcept override final;
	ArticleIdResponse Create(ArticleRequestPtr articleRequest) noexcept override final;
};
