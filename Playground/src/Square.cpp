
#include "Square.hpp"
#include <esat/draw.h>

Square::Square(){
	final_points_ = (esat::Vec2*)calloc(5, sizeof(esat::Vec2));
	points_ = (esat::Vec2*)calloc(5, sizeof(esat::Vec2));
	points_[0] = {0.0f, 0.0f};
	points_[1] = {1.0f, 0.0f};
	points_[2] = {1.0f, 1.0f};
	points_[3] = {0.0f, 1.0f};
	points_[4] = {0.0f, 0.0f};
	num_points_ = 4;
}

Square::~Square(){
	free(final_points_);
	free(points_);
}

void Square::draw(esat::Vec2* position, float scale){
	esat::Mat3 tr_points = esat::Mat3Identity();
	tr_points = esat::Mat3Multiply(tr_points, esat::Mat3Translate(position->x, position->y));
	tr_points = esat::Mat3Multiply(tr_points, esat::Mat3Scale(scale, scale));

	for(uint32_t i = 0; i < num_points_; ++i){
		final_points_[i] = esat::Mat3TransformVec2(tr_points, points_[i]);
	}
	// esat::DrawSetStrokeColor(color_.r, color_.g, color_.b, color_.a);
	// esat::DrawSetFillColor(color_.r, color_.g, color_.b, color_.a);
	esat::DrawSolidPath(&final_points_[0].x, num_points_);
}

