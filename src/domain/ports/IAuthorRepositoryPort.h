#pragma once
#include "pch.h"

class IAuthorRepositoryPort {
public:
	virtual AuthorPtr Get(String const& authorId) = 0;
};
