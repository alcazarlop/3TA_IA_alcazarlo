
#pragma once

#include <esat/math.h>
#include "Object.hpp"

class Cell {
public:
	Cell();
	virtual ~Cell();

	void add_object();
	void remove_object();

	void set_position(esat::Vec2 pos) { position_ = pos; }
	esat::Vec2 position() const { return position_; }

private:
	esat::Vec2 position_;
	Object* object_;

};