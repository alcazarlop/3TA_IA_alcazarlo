
#pragma once 

#include <vector>
#include "Node.h"
#include "SDL.h"

class Grid {
public:
	Grid();
	~Grid();

	void CreateGrid(unsigned int CellSize);
	void AgentHandler(SDL_Event* event);
	
	Node* GetNode(unsigned int index) const;
	std::vector<Node*> GetList() const;

private:
	Grid(Grid&) = delete;
	Grid(Grid&&) = delete;
	Grid(const Grid&) = delete;

	std::vector<Node*> node_list;

};