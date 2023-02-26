#pragma once
#include "pch.h"

class IArticleEndpoint {
public:
	virtual [[nodiscard]] ArticleResponse Get(String const& articleId) const noexcept = 0;
	virtual [[nodiscard]] ArticleIdResponse Create(ArticleRequestPtr articleRequest) noexcept = 0;
};