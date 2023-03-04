#pragma once
#include "pch.h"
#include "DbArticleRepository.h"
#include "Author.h"
#include "Article.h"
#include "ArticleDatabaseModel.h"

ArticlePtr DbArticleRepository::Save(Author const& author, String const& title, String const& content) noexcept
{
	/**
	 * Database integration implementation comes here
	 */
	ArticleModelPtr entity = ArticleModel::Of(author, title, content);
	LOGSTRING(std::format("DbArticleRepository->Save article to database. Author:{}, title:{}, content:{}", author.Name(), title, content))
	return entity->ToDomain();
}

ArticlePtr DbArticleRepository::Get(String const& id) const noexcept
{
	/**
	 * Database integration implementation comes here
	 */

	LOGSTRING("DbArticleRepository -> Get Article from database")

	ArticleModelPtr entity = ArticleModel::Create()
		.withId(id)
		.withAuthorName("Albert Einstein")
		.withAuthorId("1")
		.withTitle("Theory of relativity")
		.withContent("E = MC2")
		.build();

	return entity->ToDomain();
}
