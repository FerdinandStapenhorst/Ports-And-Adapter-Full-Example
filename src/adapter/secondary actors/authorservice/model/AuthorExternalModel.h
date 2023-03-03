#pragma once
#include "pch.h"

class AuthorExternalModel {
	friend class AuthorExternalModelBuilder;

public:
	AuthorExternalModel() noexcept = delete;
	AuthorExternalModel(const AuthorExternalModel& other) noexcept = delete;
	AuthorExternalModel(AuthorExternalModel&& other) noexcept = delete;
	DEFAULT_VIRTUAL_DESTRUCTOR(~AuthorExternalModel)
	

private:
	AuthorExternalModel(String const& id, String const& firstName, String const& lastName);

	String m_Id;
	String m_FirstName;
	String m_LastName;

public:
	AuthorPtr ToDomain();
	String FullName() const;
	String ToString() const;

#pragma region AuthorExternalModelBuilder

	class AuthorExternalModelBuilder {
		friend class AuthorExternalModel;

	public:
		DEFAULT_VIRTUAL_DESTRUCTOR(~AuthorExternalModelBuilder)
		

	private:
		AuthorExternalModelBuilder() noexcept = default;
		AuthorExternalModelBuilder(const AuthorExternalModelBuilder& other) noexcept = default;
		AuthorExternalModelBuilder(AuthorExternalModelBuilder&& other) noexcept = default;

		String m_Id;
		String m_FirstName;
		String m_LastName;

	public:
		AuthorExternalModelBuilder withId(String const& id);
		AuthorExternalModelBuilder withFirstName(String const& firstName);
		AuthorExternalModelBuilder withLastName(String const& lastName);
		AuthorExternalModelPtr build();
	};

#pragma endregion

public:
	static AuthorExternalModelBuilder Create();
};
