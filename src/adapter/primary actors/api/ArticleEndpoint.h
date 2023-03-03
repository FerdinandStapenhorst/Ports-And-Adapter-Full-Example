#pragma once
#include "pch.h"
#include "IArticleEndpoint.h"


class ArticleEndpoint : public IArticleEndpoint {
public:
	ArticleEndpoint(const ArticleEndpoint& other) noexcept = delete;
	ArticleEndpoint(ArticleEndpoint&& other) noexcept = default;
	ArticleEndpoint(IArticleFacadePtr articles);
	DEFAULT_VIRTUAL_DESTRUCTOR(~ArticleEndpoint)
	

private:
	IArticleFacadePtr m_Articles;

public:

	#pragma region IArticleEndpoint

	//@GetMapping("{articleId}")  @PathVariable("articleId")
	ArticleResponse Get(String const& articleId) const noexcept override final;
	//@PostMapping  @RequestBody
	ArticleIdResponse Create(ArticleRequestPtr articleRequest)noexcept override final;

	#pragma endregion
};
