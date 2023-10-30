
#include "Agent.hpp"
#include <esat/math.h>

#include <cstdio>

Agent::Agent(){
	set_color(255, 0, 0);
	set_position({100.0f, 100.0f});
}

Agent::~Agent(){

}

void Agent::transform() {
	esat::Mat3 final_points = esat::Mat3Identity();
	final_points = esat::Mat3Multiply(final_points, esat::Mat3Translate(position().x, position().y));
	final_points = esat::Mat3Multiply(final_points, esat::Mat3Scale(scale(), scale()));

	for(uint32_t i = 0; i < num_points(); ++i)
		tr_points()[i] = esat::Mat3TransformVec2(final_points, init_points()[i]);

}