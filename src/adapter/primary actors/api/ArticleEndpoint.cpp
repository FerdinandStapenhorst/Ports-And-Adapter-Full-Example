#include "pch.h"
#include "ArticleEndpoint.h"
#include "ArticleFacade.h"
#include "Article.h"
#include "ArticleIdResponse.h"
#include "ArticleResponse.h"
#include "ArticleRequest.h"

ArticleEndpoint::ArticleEndpoint(IArticleFacadePtr articles) :
	m_Articles{ std::move(articles) }
{}

ArticleResponse ArticleEndpoint::Get(String const& articleId) const noexcept
{
	std::cout << "ArticleEndpoint -> Get called" << std::endl;
	return m_Articles->Get(articleId);
}

ArticleIdResponse ArticleEndpoint::Create(ArticleRequestPtr articleRequest) noexcept
{
	std::cout << "ArticleEndpoint -> Create called" << std::endl;
	return m_Articles->Create(std::move(articleRequest));
}