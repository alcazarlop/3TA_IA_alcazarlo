
#include "Renderer.h"
#include "SDL.h"
#include "Application.h"

bool Renderer::Render_Already_Exist = false;
std::vector<Drawable> Renderer::draw_list;

Renderer::Renderer(){

}

Renderer::~Renderer(){
	draw_list.clear();
}

Renderer* Renderer::CreateRenderer(){
	if(!Renderer::Render_Already_Exist){
		Renderer::Render_Already_Exist = true;
		return new Renderer();
	}
	return nullptr;
}

void Renderer::Draw(){
	for(unsigned int i = 0; i < draw_list.size(); ++i){
		SDL_SetRenderDrawColor(Application::Render(), draw_list[i].r, draw_list[i].g, draw_list[i].b, draw_list[i].a);
		SDL_RenderFillRect(Application::Render(), &draw_list[i].rect);
		SDL_RenderDrawRect(Application::Render(), &draw_list[i].rect);
	}
}