#pragma once
#include "pch.h"

class ArticleConfig {

public:
    ArticleConfig() noexcept = default;
    ArticleConfig(const ArticleConfig& other) noexcept = default;
    ArticleConfig(ArticleConfig&& other) noexcept = default;
    virtual ~ArticleConfig() noexcept = default;



    /*@Bean
        ArticlePublisher articleEventPublisher(final ArticleMessageSender eventPublisher,
            final List<SocialMediaPublisher> _SocialMediaPublishers,
            final List<AuthorNotifier> _ArticleAuthorNotifiers) {
        return new ArticlePublisher(eventPublisher,
            _SocialMediaPublishers,
            _ArticleAuthorNotifiers);
    }

    @Bean
        ArticleService articleService(final ArticleRepository articleRepository,
            final AuthorRepository authorRepository,
            final ArticlePublisher articleEventPublisher
        ) {
        return new ArticleService(
            articleRepository,
            authorRepository,
            articleEventPublisher);
    }*/

};
