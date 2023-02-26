#pragma once
#include "pch.h"

class ArticleSmsModel {
	
public:
	ArticleSmsModel() noexcept = delete;
	ArticleSmsModel(const ArticleSmsModel& other) noexcept = delete;
	ArticleSmsModel(ArticleSmsModel&& other) noexcept = default; //required
	virtual ~ArticleSmsModel() = default;

private:
	friend class AuthorSmsNotifier;
	ArticleSmsModel(String const& recipientId, String const& text);

	static constexpr const char* CONTENT = "Please check your email. We have sent you publication details of the article: >>{}<<";
	String m_RecipientId;
	String m_Text;

public:
	static ArticleSmsModel Of(Article const& article);
	String ToString();
};
