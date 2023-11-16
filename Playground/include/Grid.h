
#pragma once 

#include <vector>
#include "Node.h"

class Grid {
public:
	Grid();
	~Grid();

	void CreateGrid(unsigned int CellSize);
	void AgentHandler();
	
	Node* GetNode(unsigned int index) const;
	std::vector<Node*> GetList() const;

private:
	Grid(Grid&) = delete;
	Grid(Grid&&) = delete;
	Grid(const Grid&) = delete;

	static bool Grid_Already_Exist;	

	std::vector<Node*> node_list;

};