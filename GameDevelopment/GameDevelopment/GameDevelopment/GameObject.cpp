#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* textureSheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(textureSheet);

	xpos = x;
	ypos = y;

}


GameObject::~GameObject()
{
}

void GameObject::Update()
{
	xpos++;
	ypos++;
	
	srcRect.h = 512;//512
	srcRect.w = 512;//512
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w / 5;
	destRect.h = srcRect.w / 5;

}

void GameObject::Render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);

}