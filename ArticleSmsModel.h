#pragma once
#include "pch.h"


class ArticleSmsModel {
	friend class AuthorSmsNotifier;

private:
	ArticleSmsModel() noexcept = delete;
	ArticleSmsModel(const ArticleSmsModel& other) noexcept = default;
	ArticleSmsModel(ArticleSmsModel&& other) noexcept = default;
	virtual ~ArticleSmsModel() noexcept = default;
	ArticleSmsModel(String const& recipientId, String const& _Text);

	static constexpr const char* CONTENT = "Please check your email. We have sent you publication details of the article: >>{}<<";
	String _RecipientId;
	String _Text;


public:
	static ArticleSmsModel Of(ArticlePtr const article);
	String ToString();
};
