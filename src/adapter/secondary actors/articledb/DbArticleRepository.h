#pragma once
#include "pch.h"
#include "IArticleRepositoryPort.h"

class DbArticleRepository : public IArticleRepositoryPort {
public:
	DbArticleRepository() noexcept = default;
	DbArticleRepository(const DbArticleRepository& other) noexcept = delete;
	DEFAULT_VIRTUAL_DESTRUCTOR(~DbArticleRepository)
	

public:

	#pragma region IArticleRepositoryPort

	[[nodiscard]] ArticlePtr Save(Author const& author, String const& title, String const& content) noexcept override final;
	[[nodiscard]] ArticlePtr Get(String const& id) const noexcept override final;

	#pragma endregion


};