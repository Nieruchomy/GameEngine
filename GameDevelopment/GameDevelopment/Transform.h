#pragma once
#include "Components.h"
#include "Vector2.h"


class Transform : public Component
{
public:

	Vector2 position;
	Vector2 velocity;

	int speed = 3;

	int height = 32;
	int width = 32;
	int scale = 1;

	Transform()
	{
		position.zero();
	}

	Transform(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	Transform(float x, float y, int h, int w, int _scale)
	{
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = _scale;
	}

	Transform(int _scale)
	{
		position.zero();
		scale = _scale;
	}
	void init() override
	{
		velocity.zero();
	}
	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};