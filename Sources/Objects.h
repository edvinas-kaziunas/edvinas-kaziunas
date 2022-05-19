#pragma once
#include <cstdlib>
#include "Defines.h"

class Object
{
protected:
	float x, y;

public:
	float GetX() { return x; }

	float GetY() { return y; }

	virtual float SpriteLeft() = 0;

	virtual float SpriteRight() = 0;

	virtual float SpriteTop() = 0;

	virtual float SpriteBottom() = 0;
};

class Car : public Object
{
private:
	const float dx = 10.0f;
public:
	Car()
	{
		Respawn();
	}
	void operator ++()
	{
		x += dx;
	}
	void operator --()
	{
		x -= dx;
	}
	void Respawn()
	{
		x = WINDOW_WIDTH / 2;
		y = 100;
	}

	float SpriteLeft() { return x + 52; }
	float SpriteRight() { return x + 110; }
	float SpriteTop() { return y; }
	float SpriteBottom() { return y + 135; }
};

class MovingObject : public Object
{
protected:
	float dy;
public:
	MovingObject(float dy) : dy(dy)
	{
		Respawn();
	}
	void MoveUp()
	{
		y -= dy;
	}
	void Respawn()
	{
		y = (float)WINDOW_HEIGHT - 20 * (rand() % 3);
		x = float(rand() % (WINDOW_WIDTH - PLATES_WIDTH));
	}
};

class Enemy : public MovingObject
{
public:
	Enemy() : MovingObject(5.0f) { }

	float SpriteLeft() { return x + 52; }
	float SpriteRight() { return x + 110; }
	float SpriteTop() { return y; }
	float SpriteBottom() { return y + 135; }
};

class Powerup : public MovingObject
{
public:
	Powerup(float speed) : MovingObject(speed) { }

	float SpriteLeft() { return x; }
	float SpriteRight() { return x + 52; }
	float SpriteTop() { return y; }
	float SpriteBottom() { return y + 135; }
};

