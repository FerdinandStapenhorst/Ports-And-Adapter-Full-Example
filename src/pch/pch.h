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

#define DEFAULT_CONSTRUCTOR(className) className() noexcept {std::cout << "  " << #className << " Ctor"<< std::endl;}
#define DEFAULT_CONSTRUCTOR_DELETE(className) className() noexcept = delete;
#define LOGSTRING_CTOR(className) std::cout << "  " << #className << " Ctor" << std::endl;
#define DEFAULT_VIRTUAL_DESTRUCTOR(className) virtual className() {std::cout << "  " << #className << " Dtor" << std::endl;}
//#define DEFAULT_VIRTUAL_DESTRUCTOR(className) virtual className() {}


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
using AuthorPtr						= std::unique_ptr<Author>;
using ArticlePtr					= std::unique_ptr<Article>;
//Service
using IArticlePublisherPtr			= std::unique_ptr<IArticlePublisher>;
using IArticleServicePtr			= std::unique_ptr<IArticleService>;
//Facade
using IArticleFacadePtr				= std::unique_ptr<IArticleFacade>;
//Pointer to the secondary ports
using IArticleRepositoryPortPtr		= std::unique_ptr<IArticleRepositoryPort>;
using IAuthorRepositoryPortPtr		= std::unique_ptr<IAuthorRepositoryPort>;
using IArticleMessageSenderPortPtr	= std::unique_ptr<IArticleMessageSenderPort>;
using ISocialMediaPublisherPortPtr	= std::unique_ptr<ISocialMediaPublisherPort>;
using IAuthorNotifierPortPtr		= std::unique_ptr<IAuthorNotifierPort>;
//Database Adapter model
using ArticleModelPtr				= std::unique_ptr<ArticleModel>;
//Author service model
using AuthorExternalModelPtr		= std::unique_ptr<AuthorExternalModel>;
//Social media Adapter
using ITwitterClientPtr				= std::unique_ptr<ITwitterClient>;
//API models
using ArticleRequestPtr				= std::unique_ptr<ArticleRequest>;
using ArticleResponsePtr			= std::unique_ptr<ArticleResponse>;
//API Endpoint 
using IArticleEndpointPtr			= std::unique_ptr<IArticleEndpoint>;

//Create instance helper
template <typename T>
std::unique_ptr<T> CreateUniqueInstance(T* p) {
	return std::unique_ptr<T>(p);
}

//Tools
struct Tools
{
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