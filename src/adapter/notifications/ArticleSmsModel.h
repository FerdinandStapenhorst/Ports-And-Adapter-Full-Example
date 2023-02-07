#pragma once
#include "pch.h"

class ArticleSmsModel {
	friend class AuthorSmsNotifier;
public:
	ArticleSmsModel() noexcept = delete;
	ArticleSmsModel(const ArticleSmsModel& other) noexcept = delete;
	ArticleSmsModel(ArticleSmsModel&& other) noexcept = default; //required

private:

	ArticleSmsModel(String const& recipientId, String const& _Text);

	static constexpr const char* CONTENT = "Please check your email. We have sent you publication details of the article: >>{}<<";
	String _RecipientId;
	String _Text;

public:
	static ArticleSmsModel Of(ArticlePtr const article);
	String ToString();
};
