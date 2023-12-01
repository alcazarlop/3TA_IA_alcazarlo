
#pragma once 

#include "SDL.h"

class Application {
public:
	Application();
	~Application();

	int Init();
	int Run();
	void Quit();

private:
	Application(Application&) = delete;
	Application(Application&&) = delete;
	Application(const Application&) = delete;
	Application& operator=(Application&) = delete;

	SDL_Window* window;
	SDL_Renderer* renderer;
	int isRunning;

};