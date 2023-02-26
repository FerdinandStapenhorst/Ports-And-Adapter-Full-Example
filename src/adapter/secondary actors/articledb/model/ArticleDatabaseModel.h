#pragma once
#include "pch.h"

class ArticleModel {

public:
	ArticleModel(const ArticleModel& other) noexcept = delete;
	virtual ~ArticleModel() = default;

private:
	friend class ArticleModelBuilder;

	ArticleModel(String const& id, String const& title,
		String const& content, String const& authorId,
		uint32_t const& version, String const& authorName);

public:

	String m_Id;
	String m_Title;
	String m_Content;
	uint32_t m_Version;
	String m_AuthorId;
	String m_AuthorName;

public:

	String ToString() const;

	ArticlePtr ToDomain();

	static ArticleModelPtr Of(Author const &author, String const& title, String const& content);

#pragma region ArticleModelBuilder

	class ArticleModelBuilder {
	public:

	private:
		friend class ArticleModel;

		String m_Id;
		String m_Title;
		String m_Content;
		uint32_t m_Version{ 0U };
		String m_AuthorId;
		String m_AuthorName;

		ArticleModelBuilder() noexcept = default;
		ArticleModelBuilder(const ArticleModelBuilder& other) noexcept = default; //required
		ArticleModelBuilder(ArticleModelBuilder&& other) noexcept = default; //required

	public:

		ArticleModelBuilder withId(String const& id);

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
