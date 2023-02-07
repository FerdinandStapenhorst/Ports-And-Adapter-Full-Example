#pragma once

#include "pch.h"
#include "ArticleRetrievedMessage.h"

ArticleRetrievedMessage::ArticleRetrievedMessage(ArticlePtr const article, String const& sentAt) :
	_Article{ article },
	_SentAt{ sentAt }
{}

ArticleRetrievedMessage ArticleRetrievedMessage::Of(ArticlePtr const article)
{
	ArticleRetrievedMessage a(article, "Now");
	return a;
}

String ArticleRetrievedMessage::ToString()
{
	return std::format("Article >>{}<< retrieved", _Article->Title());
}