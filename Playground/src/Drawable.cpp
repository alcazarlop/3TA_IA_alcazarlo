
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

void Drawable::transform() {
	esat::Mat3 final_points = esat::Mat3Identity();
	final_points = esat::Mat3Multiply(final_points, esat::Mat3Translate(position().x, position().y));
	final_points = esat::Mat3Multiply(final_points, esat::Mat3Scale(scale(), scale()));

	for(uint32_t i = 0; i < num_points(); ++i)
		tr_points()[i] = esat::Mat3TransformVec2(final_points, init_points()[i]);

}