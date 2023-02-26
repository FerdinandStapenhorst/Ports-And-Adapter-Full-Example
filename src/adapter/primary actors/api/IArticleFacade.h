#pragma once
#include "pch.h"

class IArticleFacade {
public:
	virtual ArticleResponse Get(String const& articleId) const noexcept = 0;
	virtual ArticleIdResponse Create(ArticleRequestPtr articleRequest) noexcept = 0;
};