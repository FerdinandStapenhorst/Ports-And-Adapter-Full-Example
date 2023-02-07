#pragma once
#include "pch.h"

class ArticleResponse {
public:
	ArticleResponse() noexcept = delete;
	//ArticleResponse(const ArticleResponse& other) noexcept = delete;
	//ArticleResponse(ArticleResponse&& other) noexcept = delete;
	//virtual ~ArticleResponse() noexcept = default;

private:
	friend class ArticleFacade;

	String _Id;
	String _Title;
	String _Content;
	String _AuthorName;

	ArticleResponse(String const& id, String const& title, String const& content, String const& authorName);

public:
	static ArticleResponse Of(ArticlePtr const article);

	//@JsonProperty("id")
	String Id() const;

	//@JsonProperty("title")
	String Title() const;

	//@JsonProperty("content")
	String Content() const;

	//@JsonProperty("authorName")
	String AuthorName()const;
};
