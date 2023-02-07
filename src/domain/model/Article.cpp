#pragma once
#include "pch.h"
#include "Article.h"
#include "Author.h"

Article::Article(String const& _Id, String const& title, String const& _Content, AuthorPtr author) :
	_Id{ _Id },
	_Title{ title },
	_Content{ _Content },
	_Author{ author }
{
}

void Article::ValidateEligibilityForPublication() {
	std::cout << "Checking ValidateEligibilityForPublication: " << std::endl;

	verifyForPlagiarism();
	validateTitleLength();
	validateContentLength();
	checkPunctuation();
	checkGrammar();
	checkStyle();
	//TODO: these methods are just placeholders with empty implementation
}

String Article::Id() const {
	return _Id;
}

String Article::Title() const {
	return _Title;
}

String Article::Content() const {
	return _Content;
}

AuthorPtr Article::Author() const {
	return _Author;
}

void Article::checkGrammar() {
}

void Article::checkStyle() {
}

void Article::checkPunctuation() {
}

void Article::verifyForPlagiarism() {
}

void Article::validateContentLength() {
}

void Article::validateTitleLength() {
}

Article::ArticleBuilder Article::Create() {
	ArticleBuilder a;
	return a;
}

#pragma region ArticleBuilder

std::shared_ptr<Article> Article::ArticleBuilder::build() {
	Article* a = new Article(_Id, _Title, _Content, _Author);
	std::cout << "ArticleBuilder.build called" << std::endl;
	return std::shared_ptr<Article>(a);
}

Article::ArticleBuilder Article::ArticleBuilder::withId(String const& id) {
	_Id = id;
	return *this;
}

Article::ArticleBuilder Article::ArticleBuilder::withTitle(String const& title) {
	_Title = title;
	return *this;
}

Article::ArticleBuilder Article::ArticleBuilder::withContent(String const& content) {
	_Content = content;
	return *this;
}

Article::ArticleBuilder Article::ArticleBuilder::withAuthor(AuthorPtr author) {
	_Author = author;
	return *this;
}

#pragma endregion