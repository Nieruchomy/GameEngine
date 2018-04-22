#include "Game.h"
#include "Map.h"

GameObject* player;
SDL_Renderer* Game::renderer = nullptr;
Map* map;

Game::Game()
{
}


Game::~Game()
{
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	//Fullscreen check
	int flags = 0; //fifth parameter for the  SDL_CreateWindow
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	//Do SDL init
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {

		//Window init
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created!..." << std::endl;
		}

		//Renderer init
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!..." << std::endl;
		}

		//The game is set up by now
		isRunning = true;
		std::cout << "All subsystems initialised!..." << std::endl;

	} else {
		isRunning = false;
		std::cout << "ERROR: subsystems not initialised!..." << std::endl;
	}
	map = new Map();
	player = new GameObject("assets/mad.png", 0, 0);

}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}

void Game::update()
{
	player->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);

	//placeholder for stuff to render
	map->DrawMap();
	player->Render();

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game Cleaned" << std::endl;
}

