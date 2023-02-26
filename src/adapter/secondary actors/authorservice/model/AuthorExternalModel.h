#pragma once
#include "pch.h"

class AuthorExternalModel {
	friend class AuthorExternalModelBuilder;

public:
	AuthorExternalModel() noexcept = delete;
	AuthorExternalModel(const AuthorExternalModel& other) noexcept = delete;
	AuthorExternalModel(AuthorExternalModel&& other) noexcept = delete;
	virtual ~AuthorExternalModel() {
		std::cout << "~AuthorExternalModel" << std::endl;
	}

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
		virtual ~AuthorExternalModelBuilder() = default;

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
