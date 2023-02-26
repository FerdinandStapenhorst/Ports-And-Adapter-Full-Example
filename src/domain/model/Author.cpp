#pragma once
#include "pch.h"
#include "Author.h"

AuthorPtr Author::AuthorBuilder::build() {
	Author* a = new Author(m_Id, m_Name);
	return std::shared_ptr<Author>(a);
}

Author::Author(String const& id, String const& name) {
	m_Id = id;
	m_Name = name;
}

Author::AuthorBuilder Author::Create() {
	AuthorBuilder a;
	return a;
}

String Author::Name() const {
	return m_Name;
}

String Author::Id() const {
	return m_Id;
}

Author::AuthorBuilder Author::AuthorBuilder::withId(String const& id) {
	m_Id = id;
	return *this;
}

Author::AuthorBuilder Author::AuthorBuilder::withName(String const& name) {
	m_Name = name;
	return *this;
}