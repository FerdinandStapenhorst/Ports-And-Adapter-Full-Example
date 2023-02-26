#pragma once
#include "pch.h"

class IAuthorNotifierPort {
public:
	virtual ~IAuthorNotifierPort() {
		std::cout << "~IAuthorNotifierPort" << std::endl;
	}
	virtual void NotifyAboutCreationOf(Article const& article) const noexcept = 0;
};
