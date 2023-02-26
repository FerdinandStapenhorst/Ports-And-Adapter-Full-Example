#pragma once
#include "pch.h"

//Twitter client interface
class ITwitterClient {
public:
	virtual void Tweet(ArticleTwitterModel const articleTweet) const noexcept = 0;
};
