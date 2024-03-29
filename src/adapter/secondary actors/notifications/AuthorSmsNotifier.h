#pragma once
#include "pch.h"
#include "IAuthorNotifier.h"

class AuthorSmsNotifier : public IAuthorNotifier {  //Implement (inherit) the required port
public:
	AuthorSmsNotifier() noexcept = default; //required
	AuthorSmsNotifier(const AuthorSmsNotifier& other) noexcept = delete;
	AuthorSmsNotifier(AuthorSmsNotifier&& other) noexcept = delete;
	DEFAULT_VIRTUAL_DESTRUCTOR(~AuthorSmsNotifier)
	

public:

	void NotifyAboutCreationOf(Article const& article) const noexcept override final;
};
