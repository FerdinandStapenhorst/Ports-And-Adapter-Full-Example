//The precompiled header. The respective cpp file is pch.cpp
#pragma once
#include <string>
#include <iostream>
#include <concepts>
#include <vector>
#include <random>
#include <sstream>
#include <format>
#include <optional>

#pragma region Concepts

template<typename T>
concept IsRegularType = std::regular<T>;

#pragma endregion

//Forward declarations
class Author;
class Article;
class ArticleService;
class ArticleFacade;
class IArticleRepositoryPort;
class ArticleRequest;
class ArticleResponse;
class IAuthorRepositoryPort;
class ArticleModel;
class ArticlePublisher;
class IArticleMessageSenderPort;
class ISocialMediaPublisherPort;
class IAuthorNotifierPort;
class AuthorExternalModel;
class TwitterClient;
class ArticleTwitterModel;
class ArticleIdResponse;
class AuthorRepository;
class ArticleEndpoint;

//Usings
using String = std::string;

//Models
using AuthorPtr = std::shared_ptr <Author>;
using ArticlePtr = std::shared_ptr <Article>;

//Service
using ArticlePublisherPtr = std::shared_ptr<ArticlePublisher>;
using ArticleServicePtr = std::shared_ptr<ArticleService>;
//Facade
using ArticleFacadePtr = std::shared_ptr<ArticleFacade>;

//Pointer to the ports
using IArticleRepositoryPortPtr = std::shared_ptr<IArticleRepositoryPort>;
using IAuthorRepositoryPortPtr = std::shared_ptr<IAuthorRepositoryPort>;
using IArticleMessageSenderPortPtr = std::shared_ptr<IArticleMessageSenderPort>;
using ISocialMediaPublisherPortPtr = std::shared_ptr<ISocialMediaPublisherPort>;
using IAuthorNotifierPortPtr = std::shared_ptr <IAuthorNotifierPort>;

//Database Adapter model
using ArticleModelPtr = std::shared_ptr<ArticleModel>;

//Author service model
using AuthorExternalModelPtr = std::shared_ptr <AuthorExternalModel>;

//Social media Adapter
using TwitterClientPtr = std::shared_ptr <TwitterClient>;

//API
using ArticleRequestPtr = std::shared_ptr <ArticleRequest>;
using ArticleResponsePtr = std::shared_ptr <ArticleResponse>;
using ArticleEndpointPtr = std::shared_ptr <ArticleEndpoint>;

//Create instance helper
template <typename T>
std::shared_ptr<T> CreateInstance(T* p) {
	return std::shared_ptr<T>(p);
}

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