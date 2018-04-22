#pragma once

#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"
#include "Animation.h"
#include <map>

class Sprite : public Component
{
public:

	int animIndex = 0;

	std::map<const char*, Animation> animations;

	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	Sprite() = default;
	Sprite(const char* path)
	{
		setText(path);
	}

	~Sprite()
	{
		SDL_DestroyTexture(texture);
	}

	void setText(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

	Sprite(const char* path, bool isAnimated)
	{
		animated = isAnimated;

		Animation idle = Animation(0, 3, 100);
		Animation walk = Animation(1 , 8, 100);

		animations.emplace("idle", idle);
		animations.emplace("walk", walk);

		play("Idle");
		texture = TextureManager::LoadTexture(path);
	}

	void init() override
	{
		transform = &entity->getComponent<Transform>();
		srcRect.x = srcRect.y = 0;
		srcRect.w = 1024;
		srcRect.h = 1024;

		
	}

	void update() override
	{

		if (animated)
		{
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		srcRect.y = animIndex * transform->height;

		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}
	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
	}

	void play(const char* name)
	{
		frames = animations[name].frames;
		animIndex = animations[name].index;
		speed = animations[name].speed;
	}

private:
	Transform *transform;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;

};