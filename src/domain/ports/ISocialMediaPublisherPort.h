#pragma once
#include "pch.h"

class ISocialMediaPublisherPort {
public:
	virtual void Publish(ArticlePtr const article) = 0;
};
