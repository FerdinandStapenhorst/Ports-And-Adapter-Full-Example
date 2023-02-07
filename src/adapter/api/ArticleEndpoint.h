#pragma once
#include "pch.h"

class ArticleEndpoint {
public:
	ArticleEndpoint() noexcept = delete;
	ArticleEndpoint(const ArticleEndpoint& other) noexcept = delete;
	ArticleEndpoint(ArticleEndpoint&& other) noexcept = delete;

	ArticleEndpoint(ArticleFacadePtr const articles);

private:
	ArticleFacadePtr _Articles;

public:
	//@GetMapping("{articleId}")  @PathVariable("articleId")
	ArticleResponse Get(String const& articleId);

	//@PostMapping  @RequestBody
	ArticleIdResponse Create(ArticleRequestPtr const articleRequest);
};
