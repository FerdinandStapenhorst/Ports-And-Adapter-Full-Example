#include "pch.h"
#include "AuthorSmsNotifier.h"
#include "ArticleSmsModel.h"

void AuthorSmsNotifier::NotifyAboutCreationOf(ArticlePtr const article)
{
    /**
     * SMS system integration implementation comes here
     */
     auto articleSmsModel = ArticleSmsModel::Of(article);
}
