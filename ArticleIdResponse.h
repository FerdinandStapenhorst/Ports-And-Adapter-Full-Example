#pragma once
#include "pch.h"

class ArticleIdResponse {
public:
	ArticleIdResponse() noexcept = default;
	ArticleIdResponse(const ArticleIdResponse& other) noexcept = default;
	ArticleIdResponse(ArticleIdResponse&& other) noexcept = default;
	virtual ~ArticleIdResponse() noexcept = default;
	ArticleIdResponse(String const& _Id);

private:
	String _Id;

public:
	static ArticleIdResponse Of(String const& articleId);
	String Id()  const;
};
