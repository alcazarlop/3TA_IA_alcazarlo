
#pragma once

#include "Drawable.h"
#include <vector>

class Renderer {
public:
	~Renderer();

	static Renderer* CreateRenderer();
	void Draw();

	static void AddDrawable(Drawable draw) { draw_list.push_back(draw); }

private:
	Renderer();
	Renderer(Renderer&) = delete;
	Renderer(Renderer&&) = delete;
	Renderer(const Renderer&) = delete;

	static std::vector<Drawable> draw_list;
	static bool Render_Already_Exist;

};