
#pragma once

#include "SDL.h"

class Node {
public:
	Node(int x, int y, unsigned int id, int size);
	~Node();

	unsigned int id() const { return index_; }
	int size() const { return size_; }
	SDL_Point position() const { return position_; }
	bool isLocked() const { return isLocked_; }
	void lock() { isLocked_ = true; }

	bool isInsideBounds(int x, int y);

private:
	Node() = delete;

	SDL_Point position_;
	int size_;
	unsigned int index_;
	bool isLocked_;

};