#include "Application.h"
#include <cstdlib>

int main(int argc, char *argv[])
{
	Application* _app = new Application("SDL_Test", 800, 800);
	_app->run();
	system("PAUSE");
	return 0;
}
