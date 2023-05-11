#pragma once
#include "pch.h"

class IAuthorNotifier {
public:
	DEFAULT_VIRTUAL_DESTRUCTOR(~IAuthorNotifier)
	virtual void NotifyAboutCreationOf(Article const& article) const noexcept = 0;
};
