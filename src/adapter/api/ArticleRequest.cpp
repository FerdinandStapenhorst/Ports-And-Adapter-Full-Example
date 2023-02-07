#include "pch.h"
#include "ArticleRequest.h"
#include "Article.h"
#include "Author.h"

ArticleRequest::ArticleRequest(String const& title, String const& content, String const& authorId) :
	_Title{ title },
	_Content{ content },
	_AuthorId{ authorId }
{}

ArticleRequest::ArticleRequest(ArticlePtr const article) :
	_Title{ article->Title() },
	_Content{ article->Content() },
	_AuthorId{ article->Author()->Id() }
{}

String ArticleRequest::Title() const
{
	return _Title;
}

String ArticleRequest::Content() const
{
	return _Content;
}

String ArticleRequest::AuthorId() const
{
	return _AuthorId;
}