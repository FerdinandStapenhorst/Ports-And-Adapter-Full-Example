#pragma once
#include "pch.h"

class Article {
public:
	friend class ArticleBuilder;

	Article() noexcept = delete;
	Article(const Article& other) noexcept = delete;
	Article(Article&& other) noexcept = delete;

private:
	String _Id;
	String _Title;
	String _Content;
	AuthorPtr _Author;

	//Private constructor only used by friend class ArticleBuilder
	Article(String const& _Id, String const& title, String const& _Content, AuthorPtr author);

#pragma region ArticleBuilder
	//Builder pattern https://refactoring.guru/design-patterns/builder
public:
	class ArticleBuilder {
	public:
		friend class Article;

	private:
		String _Id;
		String _Title;
		String _Content;
		AuthorPtr _Author;
		ArticleBuilder() noexcept = default;
		ArticleBuilder(const ArticleBuilder& other) noexcept = default; //required
		ArticleBuilder(ArticleBuilder&& other) noexcept = default; //required

	public:
		ArticleBuilder withId(String const& _Id);

		ArticleBuilder withTitle(String const& title);

		ArticleBuilder withContent(String const& _Content);

		ArticleBuilder withAuthor(AuthorPtr author);

		std::shared_ptr<Article> build();
	};

#pragma endregion

#pragma region PublicMembers
public:
	static Article::ArticleBuilder Create();

	void ValidateEligibilityForPublication();

	String Id() const;

	String Title() const;

	String Content() const;

	AuthorPtr Author() const;

private:
	void checkGrammar();

	void checkStyle();

	void checkPunctuation();

	void verifyForPlagiarism();

	void validateContentLength();

	void validateTitleLength();

#pragma endregion
};
