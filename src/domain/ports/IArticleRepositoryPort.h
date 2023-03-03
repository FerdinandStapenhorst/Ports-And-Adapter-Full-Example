#pragma once
#include "pch.h"

//Article Repository Port Interface
class IArticleRepositoryPort {
public:
	DEFAULT_VIRTUAL_DESTRUCTOR(~IArticleRepositoryPort)
	virtual [[nodiscard]] ArticlePtr Save(Author const& author, String const& title, String const& content) noexcept = 0;
	virtual [[nodiscard]] ArticlePtr Get(String const& id) const noexcept = 0;
};
