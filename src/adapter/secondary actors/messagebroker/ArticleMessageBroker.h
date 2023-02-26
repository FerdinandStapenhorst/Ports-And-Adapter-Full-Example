#pragma once
#include "pch.h"
#include "IArticleMessageSenderPort.h"
#include "Article.h"

class ArticleMessageBroker : public IArticleMessageSenderPort {
public:
	ArticleMessageBroker() noexcept = default; //required
	ArticleMessageBroker(const ArticleMessageBroker& other) noexcept = delete;
	ArticleMessageBroker(ArticleMessageBroker&& other) noexcept = delete;
	virtual ~ArticleMessageBroker() {
		std::cout << "~ArticleMessageBroker" << std::endl;
	}

public:

	#pragma region IArticleMessageSenderPort

	void SendMessageForCreated(Article const& article) const noexcept override final;
	void SendMessageForRetrieved(Article const& article) const noexcept override final;

	#pragma endregion

};
