#include "pch.h"
#include "ArticleService.h"
#include "IArticleRepositoryPort.h"
#include "IAuthorNotifierPort.h"
#include "IAuthorRepositoryPort.h"
#include "Article.h"
#include "ArticlePublisher.h"
#include "Author.h"

ArticleService::ArticleService(IArticleRepositoryPortPtr articleRepository,
	IAuthorRepositoryPortPtr authorRepository, IArticlePublisherPtr eventPublisher) :
	m_ArticleRepository{ std::move(articleRepository) },
	m_AuthorRepository{ std::move(authorRepository) },
	m_EventPublisher{ std::move(eventPublisher) }
{
}

String ArticleService::Create(String const& authorId, String const& title, String const& content) noexcept
{
	auto const author = m_AuthorRepository->Get(authorId);
	auto article = m_ArticleRepository->Save(*author, title, content);
	article->ValidateEligibilityForPublication();
	m_EventPublisher->PublishCreationOf(*article);
	return article->Id();
}

ArticlePtr ArticleService::Get(String const& id) const noexcept
{
	LOGSTRING("ArticleService -> Get called")
	auto article = m_ArticleRepository->Get(id);
	m_EventPublisher->PublishRetrievalOf(*article);
	return article;
}