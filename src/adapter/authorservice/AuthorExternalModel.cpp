#pragma once
#include "pch.h"
#include "AuthorExternalModel.h"
#include "Author.h"

AuthorExternalModel::AuthorExternalModel(String const& _Id, String const& _FirstName, String const& _LastName) :
	_Id{ _Id },
	_FirstName{ _FirstName },
	_LastName{ _LastName }
{}

AuthorPtr AuthorExternalModel::ToDomain()
{
	return Author::Create()
		.withId(_Id)
		.withName(FullName())
		.build();
}

String AuthorExternalModel::FullName() const
{
	return std::format("{} {}", _FirstName, _LastName);
}

String AuthorExternalModel::ToString() const
{
	return FullName();
}

AuthorExternalModel::AuthorExternalModelBuilder AuthorExternalModel::Create()
{
	AuthorExternalModelBuilder a;
	return a;
}

AuthorExternalModel::AuthorExternalModelBuilder AuthorExternalModel::AuthorExternalModelBuilder::withId(String const& id) {
	_Id = id;
	return *this;
}

AuthorExternalModel::AuthorExternalModelBuilder AuthorExternalModel::AuthorExternalModelBuilder::withFirstName(String const& firstName)
{
	_FirstName = firstName;
	return *this;
}
AuthorExternalModel::AuthorExternalModelBuilder AuthorExternalModel::AuthorExternalModelBuilder::withLastName(String const& lastName)
{
	_LastName = lastName;
	return *this;
}

AuthorExternalModelPtr AuthorExternalModel::AuthorExternalModelBuilder::build() {
	AuthorExternalModel* a = new AuthorExternalModel(_Id, _FirstName, _LastName);
	return std::shared_ptr<AuthorExternalModel>(a);
}