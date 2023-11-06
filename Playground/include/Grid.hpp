
#pragma once

#include <cstdint>
#include <vector>
#include <esat/math.h>

#include "Agent.hpp"
#include "Node.hpp"

class Grid {
public:
	Grid(uint32_t screen_w, uint32_t screen_h, float cell_size);
	~Grid();

	void add_object(Agent& obj, uint32_t index);
	void remove_object(uint32_t index) const;
	void draw() const;

	std::vector<Node*> node_list() { return grid_; }

private:
	esat::Vec2 windowSize_; 
	std::vector<esat::Vec2> drawPoints_;
	std::vector<Node*> grid_;

};