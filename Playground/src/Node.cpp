
#include "Node.h"

Node::Node(int x, int y, unsigned int id, int size){
	position_.x = x;
	position_.y = y;
	index_ = id;
	size_ = size;
	isLocked_ = false;
}

Node::~Node(){

}

bool Node::isInsideBounds(int x, int y){
	if(x > position_.x && x < position_.x + size_ && y > position_.y && y < position_.y + size_){
		return true;
	}
	return false;
}