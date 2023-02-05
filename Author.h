#pragma once
#include "pch.h"

class Author {
public:
	friend class AuthorBuilder;

	Author() noexcept = delete;
	Author(const Author& other) noexcept = default;
	Author(Author&& other) noexcept = default;
	virtual ~Author() noexcept = default;

private:
	Author(String const& id, String const& name);
	String _Id;
	String _Name;

public:

	class AuthorBuilder {
	public:
		friend class Author;

		AuthorBuilder(AuthorBuilder&& other) noexcept = default;
		virtual ~AuthorBuilder() noexcept = default;

	private:
		AuthorBuilder() noexcept = default;
		AuthorBuilder(const AuthorBuilder& other) noexcept = default;

		String _Id;
		String  _Name;

	public:
		AuthorBuilder withId(String const& id);
		AuthorBuilder withName(String const& name);
		AuthorPtr build();
	};

public:
	static AuthorBuilder Create();
	String Name() const;
	String Id() const;
};
