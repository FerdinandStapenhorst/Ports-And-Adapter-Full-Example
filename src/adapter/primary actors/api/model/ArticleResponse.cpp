#pragma once
#include "pch.h"
#include "Article.h"
#include "Author.h"
#include "ArticleResponse.h"

ArticleResponse::ArticleResponse(String const& id, String  const& title, String const& content, String const& authorName) {
	m_Id = id;
	m_Title = title;
	m_Content = content;
	m_AuthorName = authorName;
}

ArticleResponse ArticleResponse::Of(ArticlePtr article)
{
	ArticleResponse a(article->Id(),
		article->Title(),
		article->Content(),
		article->GetAuthor().Name());
	return a;
}

String ArticleResponse::Id() const
{
	return m_Id;
}
//@JsonProperty("title")
String ArticleResponse::Title() const {
	return m_Title;
}

//@JsonProperty("content")
String ArticleResponse::Content() const {
	return m_Content;
}

//@JsonProperty("authorName")
String ArticleResponse::AuthorName()const {
	return m_AuthorName;
}