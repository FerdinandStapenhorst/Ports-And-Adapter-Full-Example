#pragma once
#include "pch.h"
#include "IAuthorRepositoryPort.h"

class AuthorRepository : public IAuthorRepositoryPort {
public:
	AuthorRepository() noexcept = default;
	AuthorRepository(const AuthorRepository& other) noexcept = delete;
	AuthorRepository(AuthorRepository&& other) noexcept = delete;

public:
	AuthorPtr Get(String const& authorId);
};
