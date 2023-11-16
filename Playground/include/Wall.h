
#pragma once

#include "Drawable.h"
#include "Renderer.h"

class Wall {
public:
	Wall(int x, int y, int size) {
		Drawable draw;
		draw.rect.x = x;
		draw.rect.y = y;
		draw.rect.w = size;
		draw.rect.h = size;
		draw.r = 0x0;
		draw.g = 0x0;
		draw.b = 0x0;
		draw.a = 0xFF;
		Renderer::AddDrawable(draw);
	}

	~Wall(){}

private:


};