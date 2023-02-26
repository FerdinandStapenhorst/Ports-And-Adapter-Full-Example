#pragma once
#include "pch.h"
#include "ArticleTwitterModel.h"
#include "Article.h"
#include "Author.h"

ArticleTwitterModel::ArticleTwitterModel(String const& twitterAccountId, String const& tweet)
{
	m_TwitterAccountId = twitterAccountId;
	m_Tweet = tweet;
}

ArticleTwitterModel ArticleTwitterModel::Of(Article const &article)
{
	String title = article.Title();
	String twitterId = article.GetAuthor().Name();
	ArticleTwitterModel a = ArticleTwitterModel(twitterId, std::format(TWEET, title, twitterId));
	return a;
}

String ArticleTwitterModel::ToString() const
{
	return m_Tweet;
}