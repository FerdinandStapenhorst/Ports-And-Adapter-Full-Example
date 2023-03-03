#pragma once
#include "pch.h"

class ArticleTwitterModel {
public:
	ArticleTwitterModel() noexcept = delete;
	ArticleTwitterModel(const ArticleTwitterModel& other) noexcept = default;//required
	DEFAULT_VIRTUAL_DESTRUCTOR(~ArticleTwitterModel)
	static constexpr const char* TWEET = "Check out the new article >>{}<< by {}";
	String m_TwitterAccountId;
	String m_Tweet;

private:
	ArticleTwitterModel(String const& twitterAccountId, String const& tweet);

public:
	static ArticleTwitterModel Of(Article const& article);
	String ToString() const;
};
