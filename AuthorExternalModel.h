#pragma once
#include "pch.h"
#include "Author.h"

class AuthorExternalModel {
private:
	friend class AuthorExternalModelBuilder;

	String id;
	String firstName;
	String lastName;

	AuthorExternalModel(String const& id, String const& firstName, String const& lastName) :
		id{ id },
		firstName{ firstName },
		lastName{ lastName }
	{
	}

	AuthorPtr ToDomain() {

		return Author::Create()
			.withId(id)
			.withName(FullName())
			.build();
	}


public:
	String FullName() const {
		return std::format("{} {}", firstName, lastName);
	}

	

	String ToString() const {
		return FullName();
	}


	class AuthorExternalModelBuilder {
	private:
		friend class AuthorExternalModel;

		AuthorExternalModelBuilder() noexcept = default;
		AuthorExternalModelBuilder(const AuthorExternalModelBuilder& other) noexcept = default;
		AuthorExternalModelBuilder(AuthorExternalModelBuilder&& other) noexcept = default;


		String id;
		String firstName;
		String lastName;

		AuthorExternalModelBuilder() {}

		AuthorExternalModelBuilder withId(long id) {
			id = id;
			return *this;
		}

		AuthorExternalModelBuilder withFirstName(String firstName) {
			firstName = firstName;
			return *this;
		}

		AuthorExternalModelBuilder withLastName(String lastName) {
			lastName = lastName;
			return *this;
		}

		AuthorExternalModelPtr build() {
			AuthorExternalModel* a = new AuthorExternalModel(id, firstName, lastName);
			return std::shared_ptr<AuthorExternalModel>(a);
		}
	};


	static AuthorExternalModelBuilder Create() {
		AuthorExternalModelBuilder a;
		return a;
	}
};
