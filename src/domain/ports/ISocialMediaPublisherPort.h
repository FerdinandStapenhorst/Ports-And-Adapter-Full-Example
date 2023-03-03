#pragma once
#include "pch.h"

class ISocialMediaPublisherPort {
public:
	DEFAULT_VIRTUAL_DESTRUCTOR(~ISocialMediaPublisherPort)
	virtual void Publish(Article const& article) const noexcept = 0;

};
