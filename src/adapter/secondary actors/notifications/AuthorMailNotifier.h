#pragma once
#include "pch.h"
#include "IAuthorNotifier.h"

class AuthorMailNotifier : public IAuthorNotifier {  //Implement (inherit) the required port
public:
	AuthorMailNotifier() noexcept = default; //required
	AuthorMailNotifier(const AuthorMailNotifier& other) noexcept = delete;
	AuthorMailNotifier(AuthorMailNotifier&& other) noexcept = delete;
	DEFAULT_VIRTUAL_DESTRUCTOR(~AuthorMailNotifier)
	

public:
	#pragma region IAuthorNotifierPort

	void NotifyAboutCreationOf(Article const& article) const noexcept override final;

	#pragma endregion

};
