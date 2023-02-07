#pragma once
#include "pch.h"
#include "ArticleTwitterModel.h"
#include "Article.h"
#include "Author.h"

ArticleTwitterModel::ArticleTwitterModel(String const& twitterAccountId, String const& tweet)
{
	_TwitterAccountId = twitterAccountId;
	_Tweet = tweet;
}

ArticleTwitterModel ArticleTwitterModel::Of(ArticlePtr const article)
{
	String title = article->Title();
	String twitterId = article->Author()->Name();
	ArticleTwitterModel a = ArticleTwitterModel(twitterId, std::format(TWEET, title, twitterId));
	return a;
}

String ArticleTwitterModel::ToString() const
{
	return _Tweet;
}