#pragma once
#include "pch.h"

class IAuthorRepository {
public:
	virtual AuthorPtr get(String const& authorId) = 0;
};
