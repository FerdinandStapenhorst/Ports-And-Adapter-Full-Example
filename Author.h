#pragma once
#include "pch.h"

class Author {
public:
	friend class AuthorBuilder;

	Author() noexcept = delete;
	Author(const Author& other) noexcept = delete;
	Author(Author&& other) noexcept = delete;

private:
	Author(String const& _Id, String const& name);
	String _Id;
	String _Name;

public:

	class AuthorBuilder {
	public:
		friend class Author;

		AuthorBuilder(AuthorBuilder&& other) noexcept = default; //required

	private:
		AuthorBuilder() noexcept = default;
		AuthorBuilder(const AuthorBuilder& other) noexcept = default;

		String _Id;
		String  _Name;

	public:
		AuthorBuilder withId(String const& _Id);
		AuthorBuilder withName(String const& name);
		AuthorPtr build();
	};

public:
	static AuthorBuilder Create();
	String Name() const;
	String Id() const;
};
