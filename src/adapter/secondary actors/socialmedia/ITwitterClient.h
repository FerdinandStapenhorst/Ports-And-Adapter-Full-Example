#pragma once
#include "pch.h"

//Twitter client interface
class ITwitterClient {
public:
	DEFAULT_VIRTUAL_DESTRUCTOR(~ITwitterClient)
	virtual void Tweet(ArticleTwitterModel const articleTweet) const noexcept = 0;
};
