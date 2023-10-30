
#pragma once

#include "Drawable.hpp"

class Agent : public Drawable {
public:
	Agent();
	~Agent();

	virtual void transform() override;

private:


};