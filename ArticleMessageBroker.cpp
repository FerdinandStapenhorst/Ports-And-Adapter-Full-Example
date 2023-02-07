#pragma once
#include "pch.h"
#include "ArticleMessageBroker.h"
#include "ArticleRetrievedMessage.h"
#include "ArticleCreatedMessage.h"

void ArticleMessageBroker::SendMessageForCreated(ArticlePtr const article)
{
	/**
	 * message broker integration implementation comes here
	 */
	auto m = ArticleCreatedMessage::Of(article);
	std::cout << "Article Message Broker: Send created event " << m.ToString() << std::endl;
}

void ArticleMessageBroker::SendMessageForRetrieved(ArticlePtr const article)
{
	/**
	 * message broker integration implementation comes here
	 */
	auto m = ArticleRetrievedMessage::Of(article);
	std::cout << "Article Message Broker: Send retrieve event " << m.ToString() << std::endl;
}