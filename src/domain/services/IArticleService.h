#pragma once
#include "pch.h"


class IArticleService {
public:
	virtual ~IArticleService() {
		std::cout << "~IArticleService" << std::endl;
	}

	virtual String Create(String const& authorId, String const& title, String const& content) noexcept = 0;
	virtual ArticlePtr Get(String const& id) const noexcept = 0;
};

