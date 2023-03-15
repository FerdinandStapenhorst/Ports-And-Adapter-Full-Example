#pragma once
#include "pch.h"
#include "IArticleFacade.h"
#include "ArticleService.h"

//Facade design pattern: https://refactoring.guru/design-patterns/facade
class ArticleFacade : public IArticleFacade {
public:
	ArticleFacade(const ArticleFacade& other) noexcept = delete;
	ArticleFacade(IArticleServicePortPtr articleService); //Inject the required port
	DEFAULT_VIRTUAL_DESTRUCTOR(~ArticleFacade)
	
private:
	IArticleServicePortPtr m_ArticleService;

public:
	ArticleResponse Get(String const& articleId) const noexcept override final;
	ArticleIdResponse Create(ArticleRequestPtr articleRequest) noexcept override final;
};
