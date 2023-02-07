#pragma once
#include "pch.h"

class ArticleModel {
public:
	ArticleModel() noexcept = delete;
	ArticleModel(const ArticleModel& other) noexcept = delete;
	ArticleModel(ArticleModel&& other) noexcept = delete;

private:
	friend class ArticleModelBuilder;

	ArticleModel(String const& _Id, String const& title,
		String const& _Content, String const& authorId,
		uint32_t const& version, String const& authorName);

public:

	String _Id;
	String _Title;
	String _Content;
	uint32_t _Version;
	String _AuthorId;
	String _AuthorName;

public:

	String ToString() const;

	ArticlePtr ToDomain();

	static ArticleModelPtr Of(AuthorPtr const author, String const& title, String const& _Content);

#pragma region ArticleModelBuilder

	class ArticleModelBuilder {
	public:

	private:
		friend class ArticleModel;

		String _Id;
		String _Title;
		String _Content;
		uint32_t _Version{ 0U };
		String _AuthorId;
		String _AuthorName;

		ArticleModelBuilder() noexcept = default;
		ArticleModelBuilder(const ArticleModelBuilder& other) noexcept = default; //required
		ArticleModelBuilder(ArticleModelBuilder&& other) noexcept = default; //required

	public:

		ArticleModelBuilder withId(String const& _Id);

		ArticleModelBuilder withTitle(String const& title);

		ArticleModelBuilder withContent(String const& content);

		ArticleModelBuilder withVersion(long const& version);

		ArticleModelBuilder withAuthorId(String const& authorId);

		ArticleModelBuilder withAuthorName(String const& authorName);

		ArticleModelPtr build();
	};

#pragma endregion

	static ArticleModelBuilder Create();
};
