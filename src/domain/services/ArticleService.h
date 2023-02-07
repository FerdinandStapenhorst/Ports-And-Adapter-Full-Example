#pragma once
#include "pch.h"

class ArticleService {
public:
	ArticleService() noexcept = delete;
	ArticleService(const ArticleService& other) noexcept = delete;
	ArticleService(ArticleService&& other) noexcept = delete;

	ArticleService(IArticleRepositoryPtr articleRepository, IAuthorRepositoryPtr authorRepository, ArticlePublisherPtr eventPublisher);

private:
	IArticleRepositoryPtr _ArticleRepository;
	IAuthorRepositoryPtr _AuthorRepository;
	ArticlePublisherPtr _EventPublisher;

public:
	String Create(String const& authorId, String const& title, String const& _Content);
	ArticlePtr Get(String const& _Id);
};
