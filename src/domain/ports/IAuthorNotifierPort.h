#pragma once
#include "pch.h"

class IAuthorNotifierPort {
public:
	virtual void NotifyAboutCreationOf(ArticlePtr const article) = 0;
};
