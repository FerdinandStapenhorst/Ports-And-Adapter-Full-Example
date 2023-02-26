#pragma once
#include "pch.h"
#include "IAuthorNotifierPort.h"

class AuthorMailNotifier : public IAuthorNotifierPort {
public:
	AuthorMailNotifier() noexcept = default; //required
	AuthorMailNotifier(const AuthorMailNotifier& other) noexcept = delete;
	AuthorMailNotifier(AuthorMailNotifier&& other) noexcept = delete;
	virtual ~AuthorMailNotifier() = default;
public:
	#pragma region IAuthorNotifierPort

	void NotifyAboutCreationOf(Article const& article) const noexcept override final;

	#pragma endregion

};
