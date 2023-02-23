#pragma once
#include "pch.h"
#include "IArticleRepositoryPort.h"

class DbArticleRepository : public IArticleRepositoryPort {
public:
	DbArticleRepository() noexcept = default;
	DbArticleRepository(const DbArticleRepository& other) noexcept = delete;

public:
	virtual ArticlePtr Save(AuthorPtr author, String const& title, String const& _Content) override;
	ArticlePtr Get(String const& _Id) override;
};