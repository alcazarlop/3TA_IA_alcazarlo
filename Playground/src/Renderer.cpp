
#include "Renderer.h"
#include "Application.h"

std::vector<Drawable> Renderer::draw_list;

Renderer::Renderer(){

}

Renderer::~Renderer(){
	draw_list.clear();
}

void Renderer::Draw(SDL_Renderer* render){
	for(unsigned int i = 0; i < draw_list.size(); ++i){
		SDL_SetRenderDrawColor(render, draw_list[i].r, draw_list[i].g, draw_list[i].b, draw_list[i].a);
		SDL_RenderFillRect(render, &draw_list[i].rect);
		SDL_RenderDrawRect(render, &draw_list[i].rect);
	}
}