#pragma once
#include "pch.h"

class IArticlePublisherPort {
public:

	DEFAULT_VIRTUAL_DESTRUCTOR(~IArticlePublisherPort)
	
	virtual void PublishCreationOf(Article const& article) const noexcept = 0;

	virtual void PublishRetrievalOf(Article const& article) const noexcept = 0;
};