#pragma once
#include "pch.h"

class Author {
public:
	friend class AuthorBuilder;

	Author() noexcept = delete;
	Author(const Author& other) noexcept = delete;
	Author(Author&& other) noexcept = delete;

private:
	String _Id;
	String _Name;

	//Private constructor only used by friend class AuthorBuilder
	Author(String const& _Id, String const& name);

#pragma region AuthorBuilder
public:

	//Builder pattern https://refactoring.guru/design-patterns/builder
	class AuthorBuilder {
	public:
		friend class Author;

		AuthorBuilder(AuthorBuilder&& other) noexcept = default; //required

	private:
		AuthorBuilder() noexcept = default;
		AuthorBuilder(const AuthorBuilder& other) noexcept = default;//required

		String _Id;
		String  _Name;

	public:
		AuthorBuilder withId(String const& _Id);
		AuthorBuilder withName(String const& name);
		AuthorPtr build();
	};

#pragma endregion

public:
	static AuthorBuilder Create();
	String Name() const;
	String Id() const;
};
