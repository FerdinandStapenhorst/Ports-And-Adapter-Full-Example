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
class ArticleRequest;
class ArticleResponse;
class ArticleModel;
class ArticleTwitterModel;
class ArticleIdResponse;
class AuthorExternalModel;

class IArticleFacade;
class IArticleService;
class IArticleRepositoryPort;
class IAuthorRepositoryPort;
class IArticlePublisher;
class IArticleMessageSenderPort;
class ISocialMediaPublisherPort;
class IAuthorNotifierPort;
class ITwitterClient;
class IArticleEndpoint;

//Usings
using String = std::string;

//Models
using AuthorPtr = std::shared_ptr<Author>;
using ArticlePtr = std::shared_ptr<Article>;

//Service
using IArticlePublisherPtr = std::shared_ptr<IArticlePublisher>;
using IArticleServicePtr = std::shared_ptr<IArticleService>;
//Facade
using IArticleFacadePtr = std::shared_ptr<IArticleFacade>;

//Pointer to the secondary ports
using IArticleRepositoryPortPtr = std::shared_ptr<IArticleRepositoryPort>;
using IAuthorRepositoryPortPtr = std::shared_ptr<IAuthorRepositoryPort>;
using IArticleMessageSenderPortPtr = std::shared_ptr<IArticleMessageSenderPort>;
using ISocialMediaPublisherPortPtr = std::shared_ptr<ISocialMediaPublisherPort>;
using IAuthorNotifierPortPtr = std::shared_ptr<IAuthorNotifierPort>;

//Database Adapter model
using ArticleModelPtr = std::shared_ptr<ArticleModel>;

//Author service model
using AuthorExternalModelPtr = std::shared_ptr<AuthorExternalModel>;

//Social media Adapter
using ITwitterClientPtr = std::shared_ptr<ITwitterClient>;

//API models
using ArticleRequestPtr = std::shared_ptr<ArticleRequest>;
using ArticleResponsePtr = std::shared_ptr<ArticleResponse>;
//API Endpoint 
using IArticleEndpointPtr = std::shared_ptr<IArticleEndpoint>;

//Create instance helper
template <typename T>
std::shared_ptr<T> CreateInstance(T* p) {
	return std::shared_ptr<T>(p);
}

template <typename T>
std::unique_ptr<T> CreateUniqueInstance(T* p) {
	return std::unique_ptr<T>(p);
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