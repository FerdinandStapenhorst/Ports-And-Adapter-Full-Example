#pragma once
#include "pch.h"
#include "Author.h"

class AuthorExternalModel {
private:
	friend class AuthorExternalModelBuilder;

	AuthorExternalModel() noexcept = default;
	AuthorExternalModel(const AuthorExternalModel& other) noexcept = default;
	AuthorExternalModel(AuthorExternalModel&& other) noexcept = default;
	AuthorExternalModel(String const& _Id, String const& _FirstName, String const& _LastName);

public:
	virtual ~AuthorExternalModel() noexcept = default;

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
	private:
		friend class AuthorExternalModel;

		AuthorExternalModelBuilder() noexcept = default;
		virtual ~AuthorExternalModelBuilder() noexcept = default;
		AuthorExternalModelBuilder(const AuthorExternalModelBuilder& other) noexcept = default;
		AuthorExternalModelBuilder(AuthorExternalModelBuilder&& other) noexcept = default;

		String _Id;
		String _FirstName;
		String _LastName;

		AuthorExternalModelBuilder withId(String const& id);

		AuthorExternalModelBuilder withFirstName(String const& firstName);

		AuthorExternalModelBuilder withLastName(String const& lastName);

		AuthorExternalModelPtr build();
	};

#pragma endregion
	static AuthorExternalModelBuilder Create();
};
