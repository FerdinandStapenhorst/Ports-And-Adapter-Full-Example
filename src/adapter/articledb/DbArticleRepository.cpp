#pragma once
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

ArticlePtr DbArticleRepository::Get(String const& _Id)
{
	/**
	 * Database integration implementation comes here
	 */
	ArticleModelPtr entity = ArticleModel::Create()
		.withId(Tools::CreateGuid())
		.withAuthorName("Albert Einstein")
		.withAuthorId("1")
		.withTitle("Theory of relativity")
		.withContent("E = MC2")
		.build();

	std::cout << "Retrieved article from Article Repository: " << entity->ToString() << std::endl;
	return entity->ToDomain();
}