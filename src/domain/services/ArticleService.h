#pragma once
#include "pch.h"
#include "ISocialMediaPublisherPort.h"
#include "IArticlePublisher.h"
#include "IAuthorRepositoryPort.h"
#include "IArticleRepositoryPort.h"
#include "IArticleService.h"

class ArticleService : public IArticleService {
public:

	ArticleService(const ArticleService& other) noexcept = default;
	ArticleService(ArticleService&& other) noexcept = default;
	
	DEFAULT_VIRTUAL_DESTRUCTOR(~ArticleService)

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
