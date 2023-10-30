
#include "Drawable.hpp"

Drawable::Drawable(){
	tr_points_ = (esat::Vec2*)calloc(4, sizeof(esat::Vec2));
	init_points_ = (esat::Vec2*)calloc(4, sizeof(esat::Vec2));
	init_points_[0] = {0.0f, 0.0f};
	init_points_[1] = {0.0f, 1.0f};
	init_points_[2] = {1.0f, 1.0f};
	init_points_[3] = {1.0f, 0.0f};
	num_points_ = 4;
}

Drawable::~Drawable(){
	free(init_points_);
	free(tr_points_);
}