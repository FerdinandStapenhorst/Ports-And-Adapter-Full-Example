#pragma once
#include "pch.h"

class IAuthorRepository {
public:
	virtual AuthorPtr Get(String const& authorId) = 0;
};
