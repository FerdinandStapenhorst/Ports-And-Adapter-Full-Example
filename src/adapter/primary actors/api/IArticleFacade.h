#pragma once
#include "pch.h"

class IArticleFacade {
public:
	virtual ~IArticleFacade() {
		std::cout << "~IArticleFacade" << std::endl;

	}
	virtual ArticleResponse Get(String const& articleId) const noexcept = 0;
	virtual ArticleIdResponse Create(ArticleRequestPtr articleRequest) noexcept = 0;
};