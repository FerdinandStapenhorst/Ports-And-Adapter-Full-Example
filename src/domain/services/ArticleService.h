#pragma once
#include "pch.h"

class IArticleService {
public:
	virtual String Create(String const& authorId, String const& title, String const& content) noexcept = 0;
	virtual ArticlePtr Get(String const& id) const noexcept = 0;
};

class ArticleService : public IArticleService {
public:

	ArticleService(const ArticleService& other) noexcept = delete;
	virtual ~ArticleService() = default;
	ArticleService(IArticleRepositoryPortPtr articleRepository, 
				   IAuthorRepositoryPortPtr authorRepository, 
				   IArticlePublisherPtr eventPublisher);

private:
	IArticleRepositoryPortPtr m_ArticleRepository;
	IAuthorRepositoryPortPtr m_AuthorRepository;
	IArticlePublisherPtr m_EventPublisher;

public:
	String Create(String const& authorId, String const& title, String const& content) noexcept override final;
	ArticlePtr Get(String const& id) const noexcept override final;
};
