#include "Application.h"

int main(int argc, char *argv[])
{
	Application* _app = new Application("SDL_Test", 800, 800);
	_app->run();
	return 0;
}
