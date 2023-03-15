#pragma once
#include "pch.h"
#include "ISocialMediaPublisherPort.h"
#include "IArticlePublisherPort.h"
#include "IAuthorRepositoryPort.h"
#include "IArticleRepositoryPort.h"
#include "IArticleServicePort.h"

class ArticleService : public IArticleServicePort {
public:

	ArticleService(const ArticleService& other) noexcept = default;
	ArticleService(ArticleService&& other) noexcept = default;
	
	DEFAULT_VIRTUAL_DESTRUCTOR(~ArticleService)

	ArticleService(IArticleRepositoryPortPtr articleRepository, 
				   IAuthorRepositoryPortPtr authorRepository, 
				   IArticlePublisherPortPtr eventPublisher);

private:
	IArticleRepositoryPortPtr m_ArticleRepository;
	IAuthorRepositoryPortPtr m_AuthorRepository;
	IArticlePublisherPortPtr m_EventPublisher;

public:
	String Create(String const& authorId, String const& title, String const& content) noexcept override final;
	ArticlePtr Get(String const& id) const noexcept override final;
};
