
#pragma once

#include "SDL.h"
#include "Drawable.h"
#include <vector>

class Renderer {
public:
	Renderer();
	~Renderer();

	void Draw(SDL_Renderer* render);

	static void AddDrawable(Drawable draw) { draw_list.push_back(draw); }

private:
	Renderer(Renderer&) = delete;
	Renderer(Renderer&&) = delete;
	Renderer(const Renderer&) = delete;
	Renderer& operator=(Renderer&) = delete;

	static std::vector<Drawable> draw_list;

};