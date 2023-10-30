
#include "Grid.hpp"
#include <esat/draw.h>

Grid::Grid(uint32_t screen_w, uint32_t screen_h, float cell_size){
	uint32_t cols = (uint32_t)(screen_w / cell_size) - 1;
	uint32_t rows = (uint32_t)(screen_h / cell_size) - 1;
	float offsetX = (float)(screen_w - (cols * cell_size)) / cols;
	float offsetY = (float)(screen_h - (rows * cell_size)) / rows;
	windowSize_ = {(float)screen_w, (float)screen_h };
	for(uint32_t i = 0; i < cols * rows; ++i){
		esat::Vec2 position = {(float)((i % cols) * (cell_size + offsetX)), (float)((i / rows) * (cell_size + offsetY))};
		Agent* obj = new Agent();
		obj->set_position(position);
		drawPoints_.push_back(position);
		grid_.push_back(obj);
	}
}

Grid::~Grid(){
	drawPoints_.clear();
	if(!grid_.empty()){
		for(uint32_t i = 0; i < grid_.size(); ++i)
			delete grid_[i];
		grid_.clear();
	}
}

void Grid::add_object(Agent& obj, uint32_t index) {
	obj.set_position(grid_[index]->position());
	grid_.insert(grid_.begin() + index, &obj);
}

void Grid::remove_object(uint32_t index) const {
	// grid_.insert(grid_.begin() + index, );
}

void Grid::draw() const {
	esat::DrawSetStrokeColor(128, 128, 128);
	for(uint32_t i = 0; i < drawPoints_.size(); ++i){
		esat::DrawLine(0.0f, drawPoints_[i].y, windowSize_.x, drawPoints_[i].y);
		esat::DrawLine(drawPoints_[i].x, 0.0f, drawPoints_[i].x, windowSize_.y);
	}
}

