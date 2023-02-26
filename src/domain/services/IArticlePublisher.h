#pragma once
#include "pch.h"

class IArticlePublisher {
public:

	virtual ~IArticlePublisher() {
		std::cout << "~IArticlePublisher" << std::endl;
	}
	virtual void PublishCreationOf(Article const& article) const noexcept = 0;

	virtual void PublishRetrievalOf(Article const& article) const noexcept = 0;
};