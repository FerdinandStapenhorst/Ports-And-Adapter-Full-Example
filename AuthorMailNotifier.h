#pragma once
#include "pch.h"
#include "IAuthorNotifier.h"


class AuthorMailNotifier : public IAuthorNotifier {

private:
    AuthorMailNotifier() noexcept = delete;
    AuthorMailNotifier(const AuthorMailNotifier& other) noexcept = default;
    AuthorMailNotifier(AuthorMailNotifier&& other) noexcept = default;
    virtual ~AuthorMailNotifier() noexcept = default;

public:
    virtual void NotifyAboutCreationOf(ArticlePtr const article) override;
};
