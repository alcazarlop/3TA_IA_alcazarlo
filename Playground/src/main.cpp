
#include "Application.h"

int main(int, char**) {
	Application* app = Application::CreateApplication();
	return app->Run();
}
