#pragma once
#include "pch.h"
#include "IAuthorRepositoryPort.h"

class AuthorRepository : public IAuthorRepositoryPort {
public:
	AuthorRepository() noexcept = default;
	AuthorRepository(const AuthorRepository& other) noexcept = default;
	AuthorRepository(AuthorRepository&& other) noexcept = default;
	DEFAULT_VIRTUAL_DESTRUCTOR(~AuthorRepository)
	

public:
	#pragma region IAuthorRepositoryPort

	[[nodiscard]] AuthorPtr Get(String const& authorId) const noexcept override final;

	#pragma endregion
};
