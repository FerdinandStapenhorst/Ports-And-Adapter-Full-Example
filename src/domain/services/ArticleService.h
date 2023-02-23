#pragma once
#include "pch.h"

class ArticleService {
public:

	ArticleService(const ArticleService& other) noexcept = delete;

	ArticleService(IArticleRepositoryPortPtr articleRepository, 
				   IAuthorRepositoryPortPtr authorRepository, 
				   ArticlePublisherPtr eventPublisher);

private:
	IArticleRepositoryPortPtr _ArticleRepository;
	IAuthorRepositoryPortPtr _AuthorRepository;
	ArticlePublisherPtr _EventPublisher;

public:
	String Create(String const& authorId, String const& title, String const& _Content);
	ArticlePtr Get(String const& _Id);
};
