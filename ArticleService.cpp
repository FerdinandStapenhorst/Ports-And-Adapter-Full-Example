#include "pch.h"
#include "ArticleService.h"
#include "IArticleRepository.h"
#include "IArticleRepository.h"
#include "IAuthorNotifier.h"
#include "IAuthorRepository.h"


ArticleService::ArticleService(IArticleRepositoryPtr articleRepository, 
	IAuthorRepositoryPtr authorRepository, IArticlePublisherPtr eventPublisher) :
	_ArticleRepository{ articleRepository },
	_AuthorRepository{ authorRepository },
	_EventPublisher{eventPublisher}
{
}

String ArticleService::Create(String const& authorId, String const& title, String const& _Content)
{
	auto author = _AuthorRepository->get(authorId);
	auto article = _ArticleRepository->Save(author, title, _Content);
	article->ValidateEligibilityForPublication();
	//_EventPublisher->PublishCreationOf(article);
	return article->Id();
}

ArticlePtr ArticleService::Get(String const& _Id)
{
	auto article = _ArticleRepository->Get(_Id);
	//eventPublisher.publishRetrievalOf(article);
	return article;
}
