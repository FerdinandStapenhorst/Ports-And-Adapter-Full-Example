#pragma once
#include "pch.h"
#include "Article.h"

class ISocialMediaPublisher {
public:
	virtual void Publish(ArticlePtr const article) = 0;
};
