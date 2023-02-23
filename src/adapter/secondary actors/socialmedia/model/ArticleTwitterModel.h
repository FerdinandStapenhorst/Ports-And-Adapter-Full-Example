#pragma once
#include "pch.h"

class ArticleTwitterModel {
public:
	ArticleTwitterModel() noexcept = delete;
	ArticleTwitterModel(const ArticleTwitterModel& other) noexcept = default;//required

	static constexpr const char* TWEET = "Check out the new article >>{}<< by {}";
	String _TwitterAccountId;
	String _Tweet;

private:
	ArticleTwitterModel(String const& twitterAccountId, String const& tweet);

public:
	static ArticleTwitterModel Of(ArticlePtr const article);
	String ToString() const;
};
