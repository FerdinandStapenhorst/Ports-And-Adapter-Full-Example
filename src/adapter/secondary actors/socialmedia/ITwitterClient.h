#pragma once
#include "pch.h"

//Twitter client interface
class ITwitterClient {
public:
	virtual ~ITwitterClient() {
		std::cout << "~ITwitterClient" << std::endl;
	}
	virtual void Tweet(ArticleTwitterModel const articleTweet) const noexcept = 0;
};
