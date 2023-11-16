
#include "Agent.h"
#include "Drawable.h"
#include "Renderer.h"

Agent::Agent(int x, int y, int size){
	Drawable draw;
	draw.rect.x = x;
	draw.rect.y = y;
	draw.rect.w = size;
	draw.rect.h = size;
	draw.r = 0xFF;
	draw.g = 0x00;
	draw.b = 0xFF;
	draw.a = 0xFF;
	Renderer::AddDrawable(draw);
}

Agent::~Agent(){

}
