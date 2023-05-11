#pragma once
#include "pch.h"
#include "IArticleMessageSender.h"
#include "Article.h"

class ArticleMessageBroker : public IArticleMessageSenderPort {  //Implement (inherit) the required port
public:
	ArticleMessageBroker() noexcept = default; //required
	ArticleMessageBroker(const ArticleMessageBroker& other) noexcept = delete;
	ArticleMessageBroker(ArticleMessageBroker&& other) noexcept = delete;
	DEFAULT_VIRTUAL_DESTRUCTOR(~ArticleMessageBroker)
	

public:

	#pragma region IArticleMessageSenderPort

	void SendMessageForCreated(Article const& article) const noexcept override final;
	void SendMessageForRetrieved(Article const& article) const noexcept override final;

	#pragma endregion

};
