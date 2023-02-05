#pragma once
#include "pch.h"


class Article {
public:
	friend class ArticleBuilder;

	Article() noexcept = delete;
	Article(const Article& other) noexcept = default;
	Article(Article&& other) noexcept = default;
	virtual ~Article() noexcept = default;

private:
	String _Id;
	String _Title;
	String _Content;
	AuthorPtr _Author;
	Article(String const& id, String const& title, String const& _Content, AuthorPtr author);

#pragma region ArticleBuilder

public:
	class ArticleBuilder {
	public:
		friend class Article;

		virtual ~ArticleBuilder() noexcept = default;

	private:
		String _Id;
		String _Title;
		String _Content;
		AuthorPtr _Author;
		ArticleBuilder() noexcept = default;
		ArticleBuilder(const ArticleBuilder& other) noexcept = default;
		ArticleBuilder(ArticleBuilder&& other) noexcept = default;

	public:
		ArticleBuilder withId(String const& id);

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
