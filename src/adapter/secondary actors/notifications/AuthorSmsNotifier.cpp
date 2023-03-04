#include "pch.h"
#include "AuthorSmsNotifier.h"
#include "ArticleSmsModel.h"

void AuthorSmsNotifier::NotifyAboutCreationOf(Article const& article) const noexcept
{
	/**
	 * SMS system integration implementation comes here
	 */
	auto m = ArticleSmsModel::Of(article);
	LOGSTRING(std::format("Notifying author via SMS: {}", m.ToString()))
}