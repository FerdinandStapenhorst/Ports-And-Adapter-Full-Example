#pragma once
#include "pch.h"

class IAuthorRepositoryPort {
public:
	DEFAULT_VIRTUAL_DESTRUCTOR(~IAuthorRepositoryPort)
	virtual [[nodiscard]] AuthorPtr Get(String const& authorId) const noexcept = 0;
};
