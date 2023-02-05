#pragma once
#include "pch.h"
#include "MessageBrokerArticleMessageSender.h"
#include "ArticleRetrievedMessage.h"
#include "ArticleCreatedMessage.h"


void MessageBrokerArticleMessageSender::SendMessageForCreated(ArticlePtr const article)
{
    /**
     * message broker integration implementation comes here
     */
    auto m = ArticleCreatedMessage::Of(article);
}

void MessageBrokerArticleMessageSender::SendMessageForRetrieved(ArticlePtr const article)
{
    /**
     * message broker integration implementation comes here
     */
     auto m =ArticleRetrievedMessage::Of(article);
}
