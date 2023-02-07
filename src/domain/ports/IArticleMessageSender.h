#pragma once
#include "pch.h"

class IArticleMessageSender {
public:
	virtual void SendMessageForCreated(ArticlePtr const article) = 0;
	virtual void SendMessageForRetrieved(ArticlePtr const article) = 0;
};
