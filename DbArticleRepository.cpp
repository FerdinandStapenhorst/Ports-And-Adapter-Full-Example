#include "pch.h"
#include "DbArticleRepository.h"
#include "Author.h"
#include "ArticleDatabaseModel.h"

ArticlePtr DbArticleRepository::Save(AuthorPtr author, String const& title, String const& _Content)
{
	/**
	 * Database integration implementation comes here
	 */
	ArticleModelPtr entity = ArticleModel::Of(author, title, _Content);
	return entity->ToDomain();
}

ArticlePtr DbArticleRepository::Get(String const& id)
{
	/**
	 * Database integration implementation comes here
	 */
	ArticleModelPtr entity = ArticleModel::Create()
		.withId(Tools::CreateGuid())
		.withAuthorName("William Shakespeare")
		.withAuthorId("928467")
		.withTitle("Hexagonal Architecture")
		.withContent("Lorem ipsum")
		.build();
	return entity->ToDomain();
}
