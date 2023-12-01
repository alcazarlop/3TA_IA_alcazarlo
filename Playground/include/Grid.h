
#pragma once 

#include <vector>
#include "Node.h"
#include "SDL.h"

class Grid {
public:
	Grid();
	~Grid();

	void CreateGrid(SDL_Window* window, unsigned int CellSize);
	void AgentHandler(SDL_Event* event);
	
private:
	Grid(Grid&) = delete;
	Grid(Grid&&) = delete;
	Grid(const Grid&) = delete;

	std::vector<Node*> node_list;

};