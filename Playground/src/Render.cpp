
#include "Render.hpp"
#include <esat/draw.h>
#include "Grid.hpp"

void Render::draw(Grid& grid){
	auto drawables = grid.node_list();
	for(uint32_t i = 0; i < drawables.size(); ++i){
		if(drawables[i]->canBeDraw()){
			drawables[i]->transform();
			esat::DrawSetStrokeColor(drawables[i]->color()[0], drawables[i]->color()[1], drawables[i]->color()[2], drawables[i]->color()[3]);
			esat::DrawSetFillColor(drawables[i]->color()[0], drawables[i]->color()[1], drawables[i]->color()[2], drawables[i]->color()[3]);
			esat::DrawSolidPath(&drawables[i]->tr_points()[0].x, drawables[i]->num_points());
		}
	}
}