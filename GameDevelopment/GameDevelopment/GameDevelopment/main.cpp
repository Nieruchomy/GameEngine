#include "Game.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	//FPS
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	int frameTime;

	Uint32 frameStart;

	//Game init
	game = new Game();
	game->init("My game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	//Game loop
	while (game->running())
	{

		//FPS calcs
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	int x;
	std::cin >> x;
	return 0;
}