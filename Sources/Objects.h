#pragma once
#include <cstdlib>
#include "Defines.h"

class Car
{
private:
	double px = WINDOW_WIDTH / 2, py = 100;
	const float dx = 10.0f;
public:
	void operator ++()
	{
		px += dx;
	}
	void operator --()
	{
		px -= dx;
	}
	double GetX()
	{
		return px;
	}
	double GetY()
	{
		return py;
	}
	float LeftSide() { return px; }

	float RightSide() { return px + 50; }

	float Bottom() { return py + 90; }

};

class Movement
{
protected:
	float ey, ex, dy;
public:
	virtual void MoveDown() // padaryk grynai virtualiu metodu
	{
		ey -= dy;
	}
	virtual void cmore()
	{
		ey = (float)WINDOW_HEIGHT - 20 * (rand() % 3);
		ex = float(rand() % (WINDOW_WIDTH - PLATES_WIDTH));
	}
	float GetX()
	{
		return ex;
	}
	float GetY()
	{
		return ey;
	}
	float LeftSide() { return ex; }

	float RightSide() { return ex + 20; }

	float Top() { return ey; }

	float Bottom() { return ey + 20; }

};

class Enemy1 : public Movement
{
public:
	Enemy1()
	{
		ey = (float)WINDOW_HEIGHT - 100 * (rand() % 20);
	}
	void MoveDown()
	{
		ey -= 5;
	}
	float LeftSide()
	{
		return ex;
	}
	float RightSide()
	{
		return ex + 50;
	}
	float Top()
	{
		return ey;
	}
	float Bottom()
	{
		return ey + 90;
	}
};

class Powerup : public Movement
{
public:
	Powerup()
	{
		ey = (float)WINDOW_HEIGHT - 100 * (rand() % 20);
		dy = 4;
	}

};

class Powerdown : public Movement
{
public:
	Powerdown()
	{
		ey = (float)WINDOW_HEIGHT - 100 * (rand() % 20);
	}
	void MoveDown()
	{
		ey -= 6;
	}

};
