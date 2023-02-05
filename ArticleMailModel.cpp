#include "pch.h"
#include "ArticleMailModel.h"
#include "Article.h"
#include "Author.h"

ArticleMailModel::ArticleMailModel(String const& _RecipientId,	String const& _Subject,	String const& _Content) :
	_RecipientId{ _RecipientId },
	_Subject{ _Subject },
	_Content{ _Content }
{}

ArticleMailModel ArticleMailModel::Of(ArticlePtr const article)
{
	ArticleMailModel a(article->Author()->Name(),
		std::format(SUBJECT, article->Title()),
		std::format(CONTENT, article->Content()));
	return a;
}

String ArticleMailModel::ToString()
{
	return _Subject;
}
