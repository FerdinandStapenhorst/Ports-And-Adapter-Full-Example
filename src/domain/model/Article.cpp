#pragma once
#include "pch.h"
#include "Article.h"
#include "Author.h"


Article::Article(String const& id, String const& title, String const& content, Author const& author) :
	m_Id{ id },
	m_Title{ title },
	m_Content{ content },
	m_Author{ author }
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
	return m_Id;
}

String Article::Title() const {
	return m_Title;
}

String Article::Content() const {
	return m_Content;
}

Author Article::GetAuthor() const {
	return m_Author;
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


ArticlePtr Article::ArticleBuilder::build() {
	Article* a = new Article(m_Id, m_Title, m_Content, *m_Author);
	return ArticlePtr(a);
}

Article::ArticleBuilder Article::ArticleBuilder::withId(String const& id) {
	m_Id = id;
	return *this;
}

Article::ArticleBuilder Article::ArticleBuilder::withTitle(String const& title) {
	m_Title = title;
	return *this;
}

Article::ArticleBuilder Article::ArticleBuilder::withContent(String const& content) {
	m_Content = content;
	return *this;
}

Article::ArticleBuilder Article::ArticleBuilder::withAuthor(Author const& author) {
	m_Author = &author;
	return *this;
}

#pragma endregion