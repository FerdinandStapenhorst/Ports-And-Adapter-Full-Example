#pragma once
#include "pch.h"

class ISocialMediaPublisherPort {
public:
	virtual void Publish(Article const& article) const noexcept = 0;
};
