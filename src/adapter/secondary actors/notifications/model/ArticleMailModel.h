#pragma once
#include "pch.h"

class ArticleMailModel {
public:
	ArticleMailModel() noexcept = delete;
	ArticleMailModel(const ArticleMailModel& other) noexcept = delete;
	ArticleMailModel(ArticleMailModel&& other) noexcept = default; //required
	DEFAULT_VIRTUAL_DESTRUCTOR(~ArticleMailModel)

private:
	friend class AuthorMailNotifier;

	ArticleMailModel(String const& recipientId, String const& subject, String const& content);

	static constexpr const char* SUBJECT = "You have successfully published: >>{}<<";
	static constexpr const char* CONTENT = "Check if everything is correct: >>{}<<";

	String m_RecipientId;
	String m_Subject;
	String m_Content;

public:
	static ArticleMailModel Of(Article const& article);
	String ToString();
};
