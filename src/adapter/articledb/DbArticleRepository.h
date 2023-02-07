#pragma once
#include "pch.h"
#include "IArticleRepository.h"

class DbArticleRepository : public IArticleRepository {
public:
	DbArticleRepository() noexcept = default;

private:
	DbArticleRepository(const DbArticleRepository& other) noexcept = delete;
	DbArticleRepository(DbArticleRepository&& other) noexcept = delete;

public:
	virtual ArticlePtr Save(AuthorPtr author, String const& title, String const& _Content) override;
	ArticlePtr Get(String const& _Id) override;
};