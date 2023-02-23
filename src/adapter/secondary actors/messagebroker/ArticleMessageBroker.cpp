#pragma once
#include "pch.h"
#include "ArticleMessageBroker.h"
#include "ArticleRetrievedMessageModel.h"
#include "ArticleCreatedMessageModel.h"

void ArticleMessageBroker::SendMessageForCreated(ArticlePtr const article)
{
	/**
	 * message broker integration implementation comes here
	 */
	auto m = ArticleCreatedMessageModel::Of(article);
	std::cout << "Article Message Broker: Send created event " << m.ToString() << std::endl;
}

void ArticleMessageBroker::SendMessageForRetrieved(ArticlePtr const article)
{
	/**
	 * message broker integration implementation comes here
	 */
	auto m = ArticleRetrievedMessageModel::Of(article);
	std::cout << "Article Message Broker: Send retrieve event " << m.ToString() << std::endl;
}