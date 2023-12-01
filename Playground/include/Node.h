
#pragma once

#include "SDL.h"

class Node {
public:

	enum Type {
		kEmpty = 0,
		kAgent = 1,
		kObstacle = 2,
		kTarget = 3,
	};

	Node(int x, int y, int size, Type t_id);
	~Node();
	bool isInsideBounds(int x, int y);

private:
	Node() = delete;

	SDL_Point position_;
	int size_;
	int type_id_;

};