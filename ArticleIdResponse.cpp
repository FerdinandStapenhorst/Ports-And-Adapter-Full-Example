#include "pch.h"
#include "ArticleIdResponse.h"
#pragma once
#include "pch.h"

ArticleIdResponse::ArticleIdResponse(String const& _Id) : _Id{ _Id } {}

ArticleIdResponse ArticleIdResponse::Of(String const& articleId)
{
    ArticleIdResponse a(articleId);
    return a;
}

String ArticleIdResponse::Id() const
{
    return _Id;
}
