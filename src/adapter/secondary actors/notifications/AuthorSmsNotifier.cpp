#include "pch.h"
#include "AuthorSmsNotifier.h"
#include "ArticleSmsModel.h"

void AuthorSmsNotifier::NotifyAboutCreationOf(Article const& article) const noexcept
{
	/**
	 * SMS system integration implementation comes here
	 */
	auto articleSmsModel = ArticleSmsModel::Of(article);
	std::cout << "Notifying author via SMS: " << articleSmsModel.ToString() << std::endl;
}