
#include "Grid.h"
#include "Drawable.h"
#include "Application.h"
#include "Renderer.h"
#include "Agent.h"

Grid::Grid(){

}

Grid::~Grid(){

}

void Grid::CreateGrid(SDL_Window* window, unsigned int CellSize) {
	int window_x = 0;
	int window_y = 0; 
	SDL_GetWindowSize(window, &window_x, &window_y);
	unsigned int n_cols = window_x / CellSize;
	unsigned int n_rows = window_y / CellSize;

	for(unsigned int i = 1; i < n_cols; ++i){
		Drawable cols;
		cols.rect.y = 0;
		cols.rect.w = 1;
		cols.rect.h = window_y;
		cols.rect.x = (i % n_cols) * CellSize;
		cols.r = 0x0;
		cols.g = 0x0;
		cols.b = 0x0;
		cols.a = 0x0;
		Renderer::AddDrawable(cols);
	}

	for(unsigned int i = 1; i < n_rows; ++i){
		Drawable rows;
		rows.rect.x = 0;
		rows.rect.h = 1;
		rows.rect.w = window_x;
		rows.rect.y = (i % n_rows) * CellSize;
		rows.r = 0x0;
		rows.g = 0x0;
		rows.b = 0x0;
		rows.a = 0x0;
		Renderer::AddDrawable(rows);
	}

	for(unsigned int i = 0; i < n_rows * n_cols; ++i){
		Node* node = new Node((i % n_cols) * CellSize, (i / n_cols) * CellSize, CellSize, Node::Type::kEmpty);
		node_list.push_back(node);
	}
}

void Grid::AgentHandler(SDL_Event* event) {

	// int mouse_x = 0;
	// int mouse_y = 0;

	// if(event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_RIGHT){
	// 	SDL_GetMouseState(&mouse_x, &mouse_y);
	// 	for(unsigned int i = 0; i < node_list.size(); ++i){
	// 		if(node_list[i]->isInsideBounds(mouse_x, mouse_y) && !node_list[i]->isLocked()){
	// 			Agent agent(node_list[i]->position().x, node_list[i]->position().y, node_list[i]->size());
	// 			node_list[i]->lock();
	// 		}
	// 	}
	// }

	// if(event->type == SDL_MOUSEBUTTONDOWN && event->button.button == SDL_BUTTON_LEFT){
	// 	SDL_GetMouseState(&mouse_x, &mouse_y);
	// 	for(unsigned int i = 0; i < node_list.size(); ++i){
	// 		if(node_list[i]->isInsideBounds(mouse_x, mouse_y) && !node_list[i]->isLocked()){
	// 			Wall wall(node_list[i]->position().x, node_list[i]->position().y, node_list[i]->size());
	// 			node_list[i]->lock();
	// 		}
	// 	}
	// }

}
