
#pragma once

#include <esat/math.h>
#include <cstdint>

class Object {
public:
	Object() : position_({0.0f, 0.0f}), scale_(2.0f) {}
	virtual ~Object(){}

	void set_position(esat::Vec2 position) { position_ = position; }
	esat::Vec2 position() const { return position_; }
	void set_scale(float scale) { scale_ = scale; }
	float scale() const { return scale_; }

private:
	esat::Vec2 position_;
	float scale_;

};

