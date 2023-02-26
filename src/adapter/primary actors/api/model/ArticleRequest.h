#pragma once
#include "pch.h"

class ArticleRequest {
public:
	ArticleRequest(const ArticleRequest& other) noexcept = delete;

private:
	String m_Title;
	String m_Content;
	String m_AuthorId;

public:
	//JsonProperty("title")   @JsonProperty("content")   @JsonProperty("authorId")
	ArticleRequest(String const& title, String const& content, String const& authorId);
	ArticleRequest(ArticlePtr const article);

	String Title() const;

	String Content() const;

	String AuthorId() const;
};
