#pragma once
#include "pch.h"
#include "IArticleRepository.h"


class DbArticleRepository : public IArticleRepository {
private:
	DbArticleRepository() noexcept = default;
	DbArticleRepository(const DbArticleRepository& other) noexcept = default;
	DbArticleRepository(DbArticleRepository&& other) noexcept = default;
	virtual ~DbArticleRepository() noexcept = default;

public:
	virtual ArticlePtr Save(AuthorPtr author, String const& title, String const& _Content) override;

	ArticlePtr Get(String const& _Id) override;
};