
#pragma once

#include <cstdint>
#include <esat/math.h>

class Node {
public:
	Node() : position_({0.0f, 0.0f}), scale_(2.0f) {}
	virtual ~Node() {}

	void set_position(esat::Vec2 position) { position_ = position; }
	void set_scale(float scale) { scale_ = scale; }
	esat::Vec2 position() const { return position_; }
	float scale() const { return scale_;}

protected:
	esat::Vec2 position_;
	float scale_;

};