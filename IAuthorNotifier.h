#pragma once
#include "pch.h"

class IAuthorNotifier {
public:
	virtual void NotifyAboutCreationOf(ArticlePtr const article) = 0;
};
