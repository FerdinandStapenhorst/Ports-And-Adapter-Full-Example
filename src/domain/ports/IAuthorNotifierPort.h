#pragma once
#include "pch.h"

class IAuthorNotifierPort {
public:
	virtual void NotifyAboutCreationOf(Article const& article) const noexcept = 0;
};
