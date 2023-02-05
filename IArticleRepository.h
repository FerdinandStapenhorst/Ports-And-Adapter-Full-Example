#pragma once
#include "pch.h"
#include "Article.h"

class IArticleRepository {

public:
    virtual ArticlePtr Save(AuthorPtr const author, String const& title, String const& _Content) = 0;

    virtual ArticlePtr Get(String const& _Id) = 0;
};
