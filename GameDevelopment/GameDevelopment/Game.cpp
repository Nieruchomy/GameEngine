#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"
#include "Vector2.h "
#include "Collision.h"

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;
Map* map;
Manager manager;

auto& player(manager.addEntity());
auto& wall(manager.addEntity());

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

	}
	else {
		isRunning = false;
		std::cout << "ERROR: subsystems not initialised!..." << std::endl;
	}
	map = new Map();

	//ECS implementations
	player.addComponent<Transform>(50, 50, 159, 123, 1);
	player.addComponent<Sprite>("assets/wiz.png");
	player.addComponent<InputController>();
	player.addComponent<Collider>("player");

	wall.addComponent<Transform>(1.0f, 300.0f, 300, 20, 1);
	wall.addComponent<Sprite>("assets/water.png");
	wall.addComponent<Collider>("wall");
}

void Game::handleEvents()
{


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
	manager.refresh();
	manager.update();

	if (Collision::AABB(player.getComponent<Collider>().collider, wall.getComponent<Collider>().collider))
	{
		player.getComponent<Transform>().velocity * -1;
		std::cout << "Wall hit!" << std::endl;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game Cleaned" << std::endl;
}

