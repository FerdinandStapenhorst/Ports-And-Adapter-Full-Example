#include "pch.h"
#include "AuthorMailNotifier.h"
#include "Article.h"
#include "Author.h"
#include "ArticleMailModel.h"

void AuthorMailNotifier::NotifyAboutCreationOf(ArticlePtr const article)
{
    /**
     * Mail system integration implementation comes here
     */
    auto mailModel = ArticleMailModel::Of(article);
}