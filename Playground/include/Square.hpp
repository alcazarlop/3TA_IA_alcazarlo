
#pragma once 

#include <esat/math.h>
#include <cstdint>
#include <cstdlib>


class Square {
public:
	Square();
	~Square();

	void draw(esat::Vec2* position, float scale);

private:
	esat::Vec2* points_;
	esat::Vec2* final_points_;
	uint32_t num_points_;

};