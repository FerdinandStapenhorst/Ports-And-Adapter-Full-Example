#pragma once
#include "pch.h"
#include "Article.h"
#include "Author.h"
#include "ArticleResponse.h"

ArticleResponse::ArticleResponse(String const& id, String  const& title, String const& content, String const& authorName) {
	_Id = id;
	_Title = title;
	_Content = content;
	_AuthorName = authorName;
}

ArticleResponse ArticleResponse::Of(ArticlePtr const article)
{
	ArticleResponse a(article->Id(),
		article->Title(),
		article->Content(),
		article->Author()->Name());
	return a;
}

String ArticleResponse::Id() const
{
	return _Id;
}
//@JsonProperty("title")
String ArticleResponse::Title() const {
	return _Title;
}

//@JsonProperty("content")
String ArticleResponse::Content() const {
	return _Content;
}

//@JsonProperty("authorName")
String ArticleResponse::AuthorName()const {
	return _AuthorName;
}