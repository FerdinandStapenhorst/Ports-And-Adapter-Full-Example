#pragma once
#include "pch.h"

class AuthorExternalModel {
public:
	AuthorExternalModel() noexcept = delete;
	AuthorExternalModel(const AuthorExternalModel& other) noexcept = delete;
	AuthorExternalModel(AuthorExternalModel&& other) noexcept = delete;

private:
	friend class AuthorExternalModelBuilder;

	AuthorExternalModel(String const& _Id, String const& _FirstName, String const& _LastName);

public:

private:
	String _Id;
	String _FirstName;
	String _LastName;

public:
	AuthorPtr ToDomain();

	String FullName() const;

	String ToString() const;

#pragma region AuthorExternalModelBuilder

	class AuthorExternalModelBuilder {
	public:

	private:
		friend class AuthorExternalModel;
		//AuthorExternalModelBuilder() noexcept = default;
		//AuthorExternalModelBuilder(const AuthorExternalModelBuilder& other) noexcept = delete;
		//AuthorExternalModelBuilder(AuthorExternalModelBuilder&& other) noexcept = delete;

		String _Id;
		String _FirstName;
		String _LastName;

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
