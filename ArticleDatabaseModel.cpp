#include "pch.h"
#include "ArticleDatabaseModel.h"
#include "Article.h"
#include "Author.h"

ArticleModel::ArticleModel(String const& id, String const& title, String const& _Content,
	String const& authorId, uint32_t const& version, String const& authorName) :
	_Id{ id }, _Title{ title }, _Content{ _Content }, _AuthorId{ authorId },
	_Version{ version }, _AuthorName{ authorName }
{
}

String ArticleModel::ToString() const
{
	return _Title;
}

ArticlePtr ArticleModel::ToDomain()
{
	return Article::Create()
		.withId(_Id)
		.withAuthor(Author::Create()
			.withId(_AuthorId)
			.withName(_AuthorName)
			.build())
		.withTitle(_Title)
		.withContent(_Content)
		.build();
}

ArticleModelPtr ArticleModel::Of(AuthorPtr const author, String const& title, String const& _Content)
{
	return Create()
		.withId(Tools::CreateGuid())
		.withVersion(0)
		.withAuthorId(author->Id())
		.withAuthorName(author->Name())
		.withTitle(title)
		.withContent(_Content)
		.build();
}

ArticleModel::ArticleModelBuilder ArticleModel::Create()
{
	ArticleModelBuilder a;
	return a;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withId(String const& id)
{
	_Id = id;
	return *this;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withTitle(String const& title)
{
	_Title = title;
	return *this;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withContent(String const& content)
{
	_Content = content;
	return *this;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withVersion(long const& version)
{
	_Version = version;
	return *this;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withAuthorId(String const& authorId)
{
	_AuthorId = authorId;
	return *this;
}

ArticleModel::ArticleModelBuilder ArticleModel::ArticleModelBuilder::withAuthorName(String const& authorName)
{
	_AuthorName = authorName;
	return *this;
}

std::shared_ptr<ArticleModel> ArticleModel::ArticleModelBuilder::build()
{
	ArticleModel* a = new ArticleModel(_Id, _Title, _Content, _AuthorId, _Version, _AuthorName);
	return std::shared_ptr<ArticleModel>(a);
}