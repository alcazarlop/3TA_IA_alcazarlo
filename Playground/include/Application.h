
#pragma once 

#include "SDL.h"

class Application {
public:
	~Application();

	static Application* CreateApplication();

	int Init();
	int Run();
	void Quit();

	static SDL_Window* Window() { return window; }
	static SDL_Renderer* Render() { return renderer; }

private:
	Application();
	Application(Application&) = delete;
	Application(Application&&) = delete;
	Application(const Application&) = delete;

	static SDL_Window* window;
	static SDL_Renderer* renderer;
	int isRunning;

	static bool Application_Already_Exist;

};