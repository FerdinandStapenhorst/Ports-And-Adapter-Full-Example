#pragma once
#include "pch.h"

class IAuthorRepositoryPort {
public:
	virtual [[nodiscard]] AuthorPtr Get(String const& authorId) const noexcept = 0;
};
