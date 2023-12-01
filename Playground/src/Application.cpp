
#include "Application.h"
#include "Renderer.h"
#include "Grid.h"
#include "Agent.h"

#include <cstdio>

Application::Application(){
	renderer = NULL;
	isRunning = 0;
}

Application::~Application(){

}

int Application::Init(){

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		printf("[ERROR] Could not init SDL: %s\n", SDL_GetError());
		return isRunning = -1;
	}

	if(nullptr == (window = SDL_CreateWindow("Playground", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, NULL))){
		printf("[ERROR] Could not create window: %s\n", SDL_GetError());
		SDL_Quit();
		return isRunning = -2;
	}

	if(nullptr == (renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC))){
		printf("[ERROR] Could not create renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return isRunning = -3;
	}

	return isRunning = 1;
}

int Application::Run(){

	Init();

	Grid grid;
	grid.CreateGrid(window, 32);

	Renderer render;

	SDL_Event event;

	while(isRunning){

		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);

		render.Draw(renderer);

		SDL_RenderPresent(renderer);

		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT) isRunning = 0;
			if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) isRunning = 0;
			grid.AgentHandler(&event);
		}

	}

	Quit();

	return isRunning;

}

void Application::Quit(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}