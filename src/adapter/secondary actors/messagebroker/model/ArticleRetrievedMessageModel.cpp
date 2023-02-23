#pragma once

#include "pch.h"
#include "ArticleRetrievedMessageModel.h"

ArticleRetrievedMessageModel::ArticleRetrievedMessageModel(ArticlePtr const article, String const& sentAt) :
	_Article{ article },
	_SentAt{ sentAt }
{}

ArticleRetrievedMessageModel ArticleRetrievedMessageModel::Of(ArticlePtr const article)
{
	ArticleRetrievedMessageModel a(article, "Now");
	return a;
}

String ArticleRetrievedMessageModel::ToString()
{
	return std::format("Article >>{}<< retrieved", _Article->Title());
}