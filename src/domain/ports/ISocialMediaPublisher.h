#pragma once
#include "pch.h"

class ISocialMediaPublisher {
public:
	virtual void Publish(ArticlePtr const article) = 0;
};
