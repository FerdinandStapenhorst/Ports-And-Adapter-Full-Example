#pragma once
#include "pch.h"

class ArticleMailModel {
public:
	ArticleMailModel() noexcept = delete;
	ArticleMailModel(const ArticleMailModel& other) noexcept = delete;
	ArticleMailModel(ArticleMailModel&& other) noexcept = default; //required

private:
	friend class AuthorMailNotifier;

	ArticleMailModel(String const& _RecipientId, String const& _Subject, String const& _Content);

	static constexpr const char* SUBJECT = "You have successfully published: >>{}<<";
	static constexpr const char* CONTENT = "Check if everything is correct: >>{}<<";

	String _RecipientId;
	String _Subject;
	String _Content;

public:
	static ArticleMailModel Of(ArticlePtr const article);
	String ToString();
};
