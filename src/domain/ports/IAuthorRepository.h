#pragma once
#include "pch.h"

class IAuthorRepository {
public:
	DEFAULT_VIRTUAL_DESTRUCTOR(~IAuthorRepository)
	virtual [[nodiscard]] AuthorPtr Get(String const& authorId) const noexcept = 0;
};
