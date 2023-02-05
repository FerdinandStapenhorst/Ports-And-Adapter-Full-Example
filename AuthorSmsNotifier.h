#pragma once
#include "pch.h"
#include "IAuthorNotifier.h"

class AuthorSmsNotifier : public IAuthorNotifier {
private:
    AuthorSmsNotifier() noexcept = delete;
    AuthorSmsNotifier(const AuthorSmsNotifier& other) noexcept = default;
    AuthorSmsNotifier(AuthorSmsNotifier&& other) noexcept = default;
    virtual ~AuthorSmsNotifier() noexcept = default;

public:
    virtual void NotifyAboutCreationOf(ArticlePtr const article) override;
};
