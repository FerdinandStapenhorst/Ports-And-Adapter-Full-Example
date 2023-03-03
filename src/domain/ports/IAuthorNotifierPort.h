#pragma once
#include "pch.h"

class IAuthorNotifierPort {
public:
	DEFAULT_VIRTUAL_DESTRUCTOR(~IAuthorNotifierPort)
	virtual void NotifyAboutCreationOf(Article const& article) const noexcept = 0;
};
