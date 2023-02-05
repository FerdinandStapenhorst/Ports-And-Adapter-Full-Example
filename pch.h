#pragma once
#include <string>
#include <iostream>
#include <concepts>
#include <vector>
#include <random>
#include <sstream>
#include <format>

//Forward declarations
class Author;
class Article;
class ArticleService;
class IArticleFacade;
class IArticleRepository;
class IAuthorRepository;
class ArticleModel;
class IArticlePublisher;
class IArticleMessageSender;
class ISocialMediaPublisher;
class IAuthorNotifier;
class AuthorExternalModel;


//Usings
using String = std::string;
using AuthorPtr = std::shared_ptr <Author>;
using ArticlePtr = std::shared_ptr <Article>;

using IArticleFacadePtr = std::shared_ptr<IArticleFacade>;
using ArticleServicePtr = std::shared_ptr<ArticleService>;
using IArticleRepositoryPtr = std::shared_ptr<IArticleRepository>;
using IAuthorRepositoryPtr = std::shared_ptr<IAuthorRepository>;
using IArticlePublisherPtr = std::shared_ptr<IArticlePublisher>;
using ArticleModelPtr = std::shared_ptr<ArticleModel>;
using IArticleMessageSenderPtr = std::shared_ptr<IArticleMessageSender>;
using ISocialMediaPublisherPtr = std::shared_ptr<ISocialMediaPublisher>;
using IAuthorNotifierPtr = std::shared_ptr <IAuthorNotifier>;
using AuthorExternalModelPtr = std::shared_ptr <AuthorExternalModel>;

//Tools
class Tools
{
public:
	static std::string CreateGuid()
	{
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(0, 15);
		std::uniform_int_distribution<> dis2(8, 11);

		std::stringstream ss;
		int i;
		ss << std::hex;
		for (i = 0; i < 8; i++)
			ss << dis(gen);
		ss << "-";
		for (i = 0; i < 4; i++)
			ss << dis(gen);
		ss << "-4";
		for (i = 0; i < 3; i++)
			ss << dis(gen);
		ss << "-a";
		for (i = 0; i < 3; i++)
			ss << dis(gen);
		ss << "-";
		for (i = 0; i < 12; i++)
			ss << dis2(gen);

		return ss.str();
	}
};