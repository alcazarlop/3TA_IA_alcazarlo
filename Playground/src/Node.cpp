
#include "Node.h"

Node::Node(int x, int y, int size, Type t_id){
	position_.x = x;
	position_.y = y;
	size_ = size;
	type_id_ = t_id;
}

Node::~Node(){

}

bool Node::isInsideBounds(int x, int y){
	if(x > position_.x && x < position_.x + size_ && y > position_.y && y < position_.y + size_){
		return true;
	}
	return false;
}