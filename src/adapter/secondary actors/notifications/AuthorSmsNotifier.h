#pragma once
#include "pch.h"
#include "IAuthorNotifierPort.h"

class AuthorSmsNotifier : public IAuthorNotifierPort {
public:
	AuthorSmsNotifier() noexcept = default; //required
	AuthorSmsNotifier(const AuthorSmsNotifier& other) noexcept = delete;
	AuthorSmsNotifier(AuthorSmsNotifier&& other) noexcept = delete;
	virtual ~AuthorSmsNotifier() {
		std::cout << "~AuthorSmsNotifier" << std::endl;
	}

public:

	void NotifyAboutCreationOf(Article const& article) const noexcept override final;
};
