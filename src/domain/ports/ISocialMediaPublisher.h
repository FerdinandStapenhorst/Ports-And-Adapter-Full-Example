#pragma once
#include "pch.h"

class ISocialMediaPublisher {
public:
	DEFAULT_VIRTUAL_DESTRUCTOR(~ISocialMediaPublisher)
	virtual void Publish(Article const& article) const noexcept = 0;

};
