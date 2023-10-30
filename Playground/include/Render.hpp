
#pragma once 

#include <vector>
#include <cstdint>
#include "Drawable.hpp"

class Render {
public:
	Render(){}
	~Render(){}

	void draw(std::vector<Drawable*> drawables);

private:	


};