#pragma once
#include "pch.h"
#include "IAr"

class ArticleEndpoint {

public:
    ArticleEndpoint() noexcept = default;
    ArticleEndpoint(const ArticleEndpoint& other) noexcept = delete;
    ArticleEndpoint(ArticleEndpoint&& other) noexcept = delete;
    virtual ~ArticleEndpoint() noexcept = default;

private:
    IArticleFacadePtr articles;

    ArticleEndpoint(ArticleFacade articles) {
        this.articles = articles;
    }

    @GetMapping("{articleId}")
        ArticleResponse get(@PathVariable("articleId") final String articleId) {
        return articles.get(articleId);
    }

    @PostMapping
        ArticleIdResponse create(@RequestBody final ArticleRequest articleRequest) {
        return articles.create(articleRequest);
    }

};
