#pragma once
#include "pch.h"


class ArticleModel {
private:
	friend class ArticleModelBuilder;

	String _Id;
	String _Title;
	String _Content;
	uint32_t _Version;
	String _AuthorId;
	String _AuthorName;

	ArticleModel() noexcept = default;
	ArticleModel(const ArticleModel& other) noexcept = default;
	ArticleModel(ArticleModel&& other) noexcept = default;

	ArticleModel(String const& id, String const& title,
		String const& _Content, String const& authorId,
		uint32_t const& version, String const& authorName);

public:

	String ToString() const;

	ArticlePtr ToDomain();

	static ArticleModelPtr Of(AuthorPtr const author, String const& title, String const& _Content);

#pragma region ArticleModelBuilder

	class ArticleModelBuilder {
	private:
		friend class ArticleModel;

		String _Id;
		String _Title;
		String _Content;
		uint32_t _Version{ 0U };
		String _AuthorId;
		String _AuthorName;

		ArticleModelBuilder() noexcept = default;
		ArticleModelBuilder(const ArticleModelBuilder& other) noexcept = default;
		ArticleModelBuilder(ArticleModelBuilder&& other) noexcept = default;

	public:

		ArticleModelBuilder withId(String const& id);

		ArticleModelBuilder withTitle(String const& title);

		ArticleModelBuilder withContent(String const& content);

		ArticleModelBuilder withVersion(long const& version);

		ArticleModelBuilder withAuthorId(String const& authorId);

		ArticleModelBuilder withAuthorName(String const& authorName);

		std::shared_ptr<ArticleModel> build();
	};

#pragma endregion

	static ArticleModelBuilder Create();
};
