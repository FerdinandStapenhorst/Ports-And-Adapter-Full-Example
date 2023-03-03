#pragma once
#include "pch.h"

class Author {
	friend class AuthorBuilder;

public:

	DEFAULT_CONSTRUCTOR_DELETE(Author)
	Author(const Author& other) noexcept = default;
	Author(Author&& other) noexcept = default;
	Author& operator =(Author const& other) noexcept = default;
	DEFAULT_VIRTUAL_DESTRUCTOR(~Author)

private:
	
	String m_Id;
	String m_Name;

	//Private constructor only used by friend class AuthorBuilder
	Author(String const& id, String const& name);

#pragma region AuthorBuilder
public:

	//Builder pattern https://refactoring.guru/design-patterns/builder
	class AuthorBuilder {
		friend class Author;

	public:
		AuthorBuilder(AuthorBuilder&& other) noexcept = default; //required

	private:
		AuthorBuilder() noexcept = default;
		AuthorBuilder(const AuthorBuilder& other) noexcept = default;//required

		String m_Id;
		String m_Name;

	public:
		AuthorBuilder withId(String const& id);
		AuthorBuilder withName(String const& name);
		AuthorPtr build();
	};

#pragma endregion

public:
	static AuthorBuilder Create();
	String Name() const;
	String Id() const;
};
