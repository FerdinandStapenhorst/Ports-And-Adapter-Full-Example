#pragma once
#include "pch.h"

class IArticleMessageSenderPort {
public:
	virtual ~IArticleMessageSenderPort() {
		std::cout << "~IArticleMessageSenderPort" << std::endl;
	}

	virtual void SendMessageForCreated(Article const& article) const noexcept = 0;
	virtual void SendMessageForRetrieved(Article const& article) const noexcept = 0;
};
