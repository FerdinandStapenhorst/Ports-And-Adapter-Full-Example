#pragma once
#include "pch.h"
#include "ArticleSmsModel.h"
#include "Article.h"
#include "Author.h"

ArticleSmsModel::ArticleSmsModel(String const& recipientId, String const& _Text) :
	_RecipientId{ recipientId },
	_Text{ _Text }
{}

ArticleSmsModel ArticleSmsModel::Of(ArticlePtr const article)
{
	ArticleSmsModel a(article->Author()->Name(),
		std::format(CONTENT, article->Title()));
	return a;
}

String ArticleSmsModel::ToString()
{
	return _Text;
}
