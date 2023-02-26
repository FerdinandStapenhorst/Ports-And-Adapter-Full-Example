#include "pch.h"
#include "AuthorMailNotifier.h"
#include "Article.h"
#include "Author.h"
#include "ArticleMailModel.h"

void AuthorMailNotifier::NotifyAboutCreationOf(Article const& article) const noexcept
{
	/**
	 * Mail system integration implementation comes here
	 */
	auto mailModel = ArticleMailModel::Of(article);
	std::cout << "Notifying author via E-Mail: " << mailModel.ToString() << std::endl;
}