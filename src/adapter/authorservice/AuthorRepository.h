#pragma once
#include "pch.h"
#include "IAuthorRepository.h"

class AuthorRepository : public IAuthorRepository {
public:
	AuthorRepository() noexcept = default;
	AuthorRepository(const AuthorRepository& other) noexcept = delete;
	AuthorRepository(AuthorRepository&& other) noexcept = delete;

public:
	AuthorPtr Get(String const& authorId);
};
