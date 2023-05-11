#pragma once
#include "pch.h"

class IArticleMessageSenderPort {
public:
	DEFAULT_VIRTUAL_DESTRUCTOR(~IArticleMessageSenderPort)
	virtual void SendMessageForCreated(Article const& article) const noexcept = 0;
	virtual void SendMessageForRetrieved(Article const& article) const noexcept = 0;
};
