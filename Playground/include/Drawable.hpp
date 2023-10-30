
#pragma once

#include <vector>
#include <cstdint>
#include <esat/math.h>
#include "Object.hpp"

class Drawable : public Object {
public:
	Drawable();
	virtual ~Drawable();

	void set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) { color_[0] = r; color_[1] = g; color_[2] = b; color_[3] = a; } 
	uint8_t* color() { return color_; } 

	esat::Vec2* tr_points() { return tr_points_; }
	esat::Vec2* init_points() { return init_points_; }
	uint8_t num_points() const { return num_points_; }

	virtual void transform() = 0;

private:
	uint8_t num_points_;
	esat::Vec2* tr_points_;
	esat::Vec2* init_points_;

	uint8_t color_[4];

};