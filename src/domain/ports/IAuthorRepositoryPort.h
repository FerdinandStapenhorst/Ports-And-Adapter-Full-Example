#pragma once
#include "pch.h"

class IAuthorRepositoryPort {
public:
	virtual ~IAuthorRepositoryPort() {
		std::cout << "~IAuthorRepositoryPort" << std::endl;
	}
	virtual [[nodiscard]] AuthorPtr Get(String const& authorId) const noexcept = 0;
};
