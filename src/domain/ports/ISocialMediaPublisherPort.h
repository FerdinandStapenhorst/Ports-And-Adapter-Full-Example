#pragma once
#include "pch.h"

class ISocialMediaPublisherPort {
public:
	virtual ~ISocialMediaPublisherPort() {
		std::cout << "~ISocialMediaPublisherPort" << std::endl;
	}
	virtual void Publish(Article const& article) const noexcept = 0;

};
