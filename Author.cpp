#pragma once
#include "pch.h"
#include "Author.h"

AuthorPtr Author::AuthorBuilder::build() {
	Author* a = new Author(_Id, _Name);
	return std::shared_ptr<Author>(a);
}

Author::Author(String const& id, String const& name) {
	_Id = id;
	_Name = name;
}

Author::AuthorBuilder Author::Create() {
	AuthorBuilder a;
	return a;
}

String Author::Name() const {
	return _Name;
}

String Author::Id() const {
	return _Id;
}

Author::AuthorBuilder Author::AuthorBuilder::withId(String const& id) {
	_Id = id;
	return *this;
}

Author::AuthorBuilder Author::AuthorBuilder::withName(String const& name) {
	_Name = name;	
	return *this;
}

