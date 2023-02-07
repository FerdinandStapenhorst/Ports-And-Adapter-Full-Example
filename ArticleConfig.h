#pragma once
#include "pch.h"
#include "ArticleMessageSender.h"
#include "ArticlePublisher.h"
#include "AuthorRepository.h"

class ArticleConfig {
public:
	ArticleConfig() noexcept = default;
	ArticleConfig(const ArticleConfig& other) noexcept = delete;
	ArticleConfig(ArticleConfig&& other) noexcept = delete;

	ArticlePublisher ArticleEventPublisher(IArticleMessageSenderPtr const eventPublisher,
		std::vector<ISocialMediaPublisher> const socialMediaPublishers,
		std::vector<IAuthorNotifier> const articleAuthorNotifiers) {

		ArticlePublisher a(eventPublisher, socialMediaPublishers, articleAuthorNotifiers);
		return a;
	}

	ArticleService ArticleService(IArticleRepositoryPtr const articleRepository,
		IAuthorRepository const authorRepository,
		ArticlePublisher const articleEventPublisher) {

		ArticleService a(
			articleRepository,
			authorRepository,
			articleEventPublisher);
		return a;
	}
};
