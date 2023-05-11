#pragma once
#include "pch.h"
#include "IArticleRepository.h"

class DbArticleRepository : public IArticleRepository {  //Implement (inherit) the required port
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