#pragma once
#include "pch.h"

class ArticleIdResponse {
public:
	ArticleIdResponse() noexcept = delete;
	ArticleIdResponse(const ArticleIdResponse& other) noexcept = default; //required
	ArticleIdResponse(ArticleIdResponse&& other) noexcept = default; //required
	virtual ~ArticleIdResponse() {
		std::cout << "~ArticleIdResponse" << std::endl;
	}

private:
	ArticleIdResponse(String const& id);
	String m_Id;

public:
	static ArticleIdResponse Of(String const& articleId);
	String Id() const;
};
