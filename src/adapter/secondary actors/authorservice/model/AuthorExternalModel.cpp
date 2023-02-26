#pragma once
#include "pch.h"
#include "AuthorExternalModel.h"
#include "Author.h"

AuthorExternalModel::AuthorExternalModel(String const& id, String const& firstName, String const& lastName) :
	m_Id{ id },
	m_FirstName{ firstName },
	m_LastName{ lastName }
{}

AuthorPtr AuthorExternalModel::ToDomain()
{
	return Author::Create()
		.withId(m_Id)
		.withName(FullName())
		.build();
}

String AuthorExternalModel::FullName() const
{
	return std::format("{} {}", m_FirstName, m_LastName);
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
	m_Id = id;
	return *this;
}

AuthorExternalModel::AuthorExternalModelBuilder AuthorExternalModel::AuthorExternalModelBuilder::withFirstName(String const& firstName)
{
	m_FirstName = firstName;
	return *this;
}
AuthorExternalModel::AuthorExternalModelBuilder AuthorExternalModel::AuthorExternalModelBuilder::withLastName(String const& lastName)
{
	m_LastName = lastName;
	return *this;
}

AuthorExternalModelPtr AuthorExternalModel::AuthorExternalModelBuilder::build() {
	AuthorExternalModel* a = new AuthorExternalModel(m_Id, m_FirstName, m_LastName);
	return AuthorExternalModelPtr(a);
}