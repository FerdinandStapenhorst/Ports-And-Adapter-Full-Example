#pragma once
#include "pch.h"

class ArticleService {
public:
	ArticleService() noexcept = default;
	ArticleService(const ArticleService& other) noexcept = default;
	ArticleService(ArticleService&& other) noexcept = default;
	virtual ~ArticleService() noexcept = default;
	ArticleService(IArticleRepositoryPtr articleRepository, IAuthorRepositoryPtr authorRepository, IArticlePublisherPtr eventPublisher);

private:
	IArticleRepositoryPtr _ArticleRepository;
	IAuthorRepositoryPtr _AuthorRepository;
	IArticlePublisherPtr _EventPublisher;

public:
	String Create(String const& authorId, String const& title, String const& _Content);
	ArticlePtr Get(String const& id);
};
