#include "pch.h"
#include "ArticleCreatedMessageModel.h"

ArticleCreatedMessageModel ArticleCreatedMessageModel::Of(ArticlePtr const article)
{
	ArticleCreatedMessageModel a(article, "Now");
	return a;
}

String ArticleCreatedMessageModel::ToString()
{
	return std::format("Article >>{}<< retrieved", _Article->Title());
}