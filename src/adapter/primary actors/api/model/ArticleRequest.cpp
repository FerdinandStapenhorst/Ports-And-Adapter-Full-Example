#include "pch.h"
#include "ArticleRequest.h"
#include "Article.h"
#include "Author.h"

ArticleRequest::ArticleRequest(String const& title, String const& content, String const& authorId) :
	m_Title{ title },
	m_Content{ content },
	m_AuthorId{ authorId }
{}

ArticleRequest::ArticleRequest(ArticlePtr article) :
	m_Title{ article->Title() },
	m_Content{ article->Content() },
	m_AuthorId{ article->GetAuthor().Id() }
{}

String ArticleRequest::Title() const
{
	return m_Title;
}

String ArticleRequest::Content() const
{
	return m_Content;
}

String ArticleRequest::AuthorId() const
{
	return m_AuthorId;
}