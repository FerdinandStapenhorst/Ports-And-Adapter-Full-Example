#pragma once
#include "pch.h"
#include "ArticleDatabaseModel.h"
#include "Article.h"
#include "Author.h"

ArticleModel::ArticleModel(String const& id, String const& title, String const& content,
	String const& authorId, uint32_t const& version, String const& authorName) :
	m_Id{ id }, m_Title{ title }, m_Content{ content }, m_AuthorId{ authorId },
	m_Version{ version }, m_AuthorName{ authorName }
{
}

String ArticleModel::ToString() const
{
	return m_Title;
}

ArticlePtr ArticleModel::ToDomain()
{
	return Article::Create()
		.withId(m_Id)
		.withAuthor(*Author::Create()
			.withId(m_AuthorId)
			.withName(m_AuthorName)
			.build())
		.withTitle(m_Title)
		.withContent(m_Content)
		.build();
}

ArticleModelPtr ArticleModel::Of(Author const& author, String const& title, String const& m_Content)
{
	return Create()
		.withId(Tools::CreateGuid())
		.withVersion(0)
		.withAuthorId(author.Id())
		.withAuthorName(author.Name())
		.withTitle(title)
		.withContent(m_Content)
		.build();
}

ArticleModel::ArticleModelBuilder ArticleModel::Create()
{
	ArticleModelBuilder a;
	return a;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withId(String const& id)
{
	m_Id = id;
	return *this;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withTitle(String const& title)
{
	m_Title = title;
	return *this;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withContent(String const& content)
{
	m_Content = content;
	return *this;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withVersion(long const& version)
{
	m_Version = version;
	return *this;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withAuthorId(String const& authorId)
{
	m_AuthorId = authorId;
	return *this;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withAuthorName(String const& authorName)
{
	m_AuthorName = authorName;
	return *this;
}

ArticleModelPtr ArticleModel::ArticleModelBuilder::build()
{
	ArticleModel* a = new ArticleModel(m_Id, m_Title, m_Content, m_AuthorId, m_Version, m_AuthorName);
	return ArticleModelPtr(a);
}