#pragma once
#include "pch.h"

class ArticleIdResponse {
public:
	ArticleIdResponse() noexcept = delete;
	ArticleIdResponse(const ArticleIdResponse& other) noexcept = default; //required
	ArticleIdResponse(ArticleIdResponse&& other) noexcept = default; //required

private:
	String _Id;
	ArticleIdResponse(String const& _Id);

public:
	static ArticleIdResponse Of(String const& articleId);
	String Id()  const;
};
