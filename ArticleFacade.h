#pragma once
#include "pch.h"
#include "ArticleResponse.h"

class ArticleFacade {

public:
    ArticleFacade() noexcept = default;
    ArticleFacade(const ArticleFacade& other) noexcept = default;
    ArticleFacade(ArticleFacade&& other) noexcept = default;
    virtual ~ArticleFacade() noexcept = default;

private:
    ArticleServicePtr _ArticleService;

    ArticleFacade(ArticleServicePtr const articleService) {
        _ArticleService = articleService;
    }

    /*ArticleResponse get(String const& articleId) {
        ArticleResponse a(articleId)
        final Article article = ArticleServicePtr->get(ArticleId.of(articleId));
        return ArticleResponse.of(article);
    }

    ArticleIdResponse create(final ArticleRequest articleRequest) {
        final ArticleId articleId = articleService.create(articleRequest.authorId(), articleRequest.title(), articleRequest.content());
        return ArticleIdResponse.of(articleId);
    }*/
};
