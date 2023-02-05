#pragma once

#include "pch.h"
#include "Author.h"
#include "Article.h"


int main()
{
	auto author = Author::Create().withId("1").withName("MyName").build();
	auto article = Article::Create().withAuthor(author).withId("1").build();
	
	return 0;
}

