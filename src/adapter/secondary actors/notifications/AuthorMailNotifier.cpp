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
	auto m = ArticleMailModel::Of(article);
	LOGSTRING(std::format("Notifying author via E-Mail: {}", m.ToString()))
}