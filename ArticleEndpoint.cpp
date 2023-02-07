#include "pch.h"
#include "ArticleEndpoint.h"
#include "ArticleFacade.h"
#include "Article.h"
#include "ArticleIdResponse.h"
#include "ArticleResponse.h"
#include "ArticleRequest.h"

ArticleEndpoint::ArticleEndpoint(ArticleFacadePtr const articles) :
	_Articles{ articles }
{}

ArticleResponse ArticleEndpoint::Get(String const& articleId)
{
	std::cout << "ArticleEndpoint -> Get called" << std::endl;
	return _Articles->Get(articleId);
}

ArticleIdResponse ArticleEndpoint::Create(ArticleRequestPtr const articleRequest)
{
	std::cout << "ArticleEndpoint -> Create called" << std::endl;
	return _Articles->Create(articleRequest);
}