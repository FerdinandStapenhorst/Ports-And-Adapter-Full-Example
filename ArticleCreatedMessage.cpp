#include "pch.h"
#include "ArticleCreatedMessage.h"

ArticleCreatedMessage ArticleCreatedMessage::Of(ArticlePtr const article)
{
    ArticleCreatedMessage a(article, "Now");
    return a;
}

String ArticleCreatedMessage::ToString()
{
    return std::format("Article >>{}<< retrieved", _Article->Title());
}
