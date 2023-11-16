
#include "Application.h"
#include "Renderer.h"
#include "Grid.h"
#include "Agent.h"

#include <cstdio>

bool Application::Application_Already_Exist = false;
SDL_Window* Application::window = NULL;
SDL_Renderer* Application::renderer = NULL;

Application::Application(){
	renderer = NULL;
	isRunning = 0;
}

Application::~Application(){

}

Application* Application::CreateApplication(){
	if(!Application::Application_Already_Exist){
		Application::Application_Already_Exist = true;
		return new Application();
	}
	return nullptr;
}

int Application::Init(){

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		printf("[ERROR] Could not init SDL: %s\n", SDL_GetError());
		return isRunning = -1;
	}

	if(nullptr == (Application::window = SDL_CreateWindow("Playground", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, NULL))){
		printf("[ERROR] Could not create window: %s\n", SDL_GetError());
		SDL_Quit();
		return isRunning = -2;
	}

	if(nullptr == (Application::renderer = SDL_CreateRenderer(Application::window, -1, SDL_RENDERER_PRESENTVSYNC))){
		printf("[ERROR] Could not create renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(Application::window);
		SDL_Quit();
		return isRunning = -3;
	}

	return isRunning = 1;
}

int Application::Run(){

	Init();

	Grid grid;
	grid.CreateGrid(32);

	Renderer* render = Renderer::CreateRenderer();

	SDL_Event event;

	while(isRunning){

		SDL_SetRenderDrawColor(Application::renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(Application::renderer);

		render->Draw();

		SDL_RenderPresent(Application::renderer);

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
	SDL_DestroyWindow(Application::window);
	SDL_DestroyRenderer(Application::renderer);
	SDL_Quit();
}