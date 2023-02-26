#pragma once
#include "pch.h"
#include "IAuthorRepositoryPort.h"

class AuthorRepository : public IAuthorRepositoryPort {
public:
	AuthorRepository() noexcept = default;
	AuthorRepository(const AuthorRepository& other) noexcept = delete;
	AuthorRepository(AuthorRepository&& other) noexcept = delete;
	virtual ~AuthorRepository() = default;

public:
	#pragma region IAuthorRepositoryPort

	[[nodiscard]] AuthorPtr Get(String const& authorId) const noexcept override final;

	#pragma endregion
};
