#pragma once
#include "pch.h"
#include "IAuthorNotifierPort.h"

class AuthorSmsNotifier : public IAuthorNotifierPort {
public:
	AuthorSmsNotifier() noexcept = default; //required
	AuthorSmsNotifier(const AuthorSmsNotifier& other) noexcept = delete;
	AuthorSmsNotifier(AuthorSmsNotifier&& other) noexcept = delete;
	DEFAULT_VIRTUAL_DESTRUCTOR(~AuthorSmsNotifier)
	

public:

	void NotifyAboutCreationOf(Article const& article) const noexcept override final;
};
