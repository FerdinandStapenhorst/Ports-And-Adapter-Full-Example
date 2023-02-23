#include "pch.h"
#include "ArticleService.h"
#include "IArticleRepositoryPort.h"
#include "IAuthorNotifierPort.h"
#include "IAuthorRepositoryPort.h"
#include "Article.h"
#include "ArticlePublisher.h"

ArticleService::ArticleService(IArticleRepositoryPortPtr articleRepository,
	IAuthorRepositoryPortPtr authorRepository, ArticlePublisherPtr eventPublisher) :
	_ArticleRepository{ articleRepository },
	_AuthorRepository{ authorRepository },
	_EventPublisher{ eventPublisher }
{
}

String ArticleService::Create(String const& authorId, String const& title, String const& _Content)
{
	auto author = _AuthorRepository->Get(authorId);
	auto article = _ArticleRepository->Save(author, title, _Content);
	article->ValidateEligibilityForPublication();
	_EventPublisher->PublishCreationOf(article);
	return article->Id();
}

ArticlePtr ArticleService::Get(String const& _Id)
{
	auto article = _ArticleRepository->Get(_Id);
	_EventPublisher->PublishRetrievalOf(article);
	return article;
}