#pragma once
#include "pch.h"
#include "Author.h"

class Article {
	friend class ArticleBuilder;

public:
	DEFAULT_CONSTRUCTOR_DELETE(Article)
	Article(const Article& other) noexcept = default;
	Article(Article&& other) noexcept = default;
	DEFAULT_VIRTUAL_DESTRUCTOR(~Article)

private:

	String m_Id;
	String m_Title;
	String m_Content;
	Author m_Author;

	
	//Private constructor only used by friend class ArticleBuilder
	Article(String const& id, String const& title, String const& content, Author const& author);

#pragma region ArticleBuilder
	//Builder pattern https://refactoring.guru/design-patterns/builder
public:
	class ArticleBuilder {
		friend class Article;

	private:
		ArticleBuilder() noexcept = default;

		String m_Id;
		String m_Title;
		String m_Content;
		Author const* m_Author{ nullptr };

		
		ArticleBuilder(const ArticleBuilder& other) noexcept = default; //required
		ArticleBuilder(ArticleBuilder&& other) noexcept = default; //required

	public:
		ArticleBuilder withId(String const& id);

		ArticleBuilder withTitle(String const& title);

		ArticleBuilder withContent(String const& content);

		ArticleBuilder withAuthor(Author const& author);

	 	ArticlePtr build();
	};

#pragma endregion

#pragma region PublicMembers
public:
	static Article::ArticleBuilder Create();

	void ValidateEligibilityForPublication();

	String Id() const;

	String Title() const;

	String Content() const;

	Author GetAuthor() const;

private:
	void checkGrammar();

	void checkStyle();

	void checkPunctuation();

	void verifyForPlagiarism();

	void validateContentLength();

	void validateTitleLength();

#pragma endregion
};
