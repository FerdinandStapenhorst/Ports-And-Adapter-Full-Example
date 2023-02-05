#pragma once
#include "pch.h"

class ArticleModel {
private:
	friend class ArticleModelBuilder;
	ArticleModel() noexcept = default;
	ArticleModel(const ArticleModel& other) noexcept = default;

	ArticleModel(ArticleModel&& other) noexcept = default;
	ArticleModel(String const& _Id, String const& title,
		String const& _Content, String const& authorId,
		uint32_t const& version, String const& authorName);

public:
	virtual ~ArticleModel() noexcept = default;

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

		ArticleModelBuilder withId(String const& _Id);

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
