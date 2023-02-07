#pragma once
#include "pch.h"
#include "AuthorRepository.h"
#include "AuthorExternalModel.h"

AuthorPtr AuthorRepository::Get(String const& authorId)
{
	/**
	 * external author service integration implementation comes here
	 */

	AuthorExternalModelPtr author = AuthorExternalModel::Create()
		.withId("1")
		.withFirstName("Albert")
		.withLastName("Einstein")
		.build();

	std::cout << "Retrieved author from Author Repository: " << author->ToString() << std::endl;
	return author->ToDomain();
}