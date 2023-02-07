#pragma once
#include "pch.h"
#include "IAuthorNotifier.h"

class AuthorMailNotifier : public IAuthorNotifier {
public:
	AuthorMailNotifier() noexcept = default; //required
	AuthorMailNotifier(const AuthorMailNotifier& other) noexcept = delete;
	AuthorMailNotifier(AuthorMailNotifier&& other) noexcept = delete;

public:
	virtual void NotifyAboutCreationOf(ArticlePtr const article) override;
};
