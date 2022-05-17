#pragma once

#include "Defines.h"

class Car
{
public:
	float LeftSide() { return px; }

	float RightSide() { return px + 50; }

	float Bottom() { return py + 90; }

	float px = 0, py = 0; // virsutinio kairiojo kampo koordinates
};

class Movement
{
public:
	float LeftSide() { return ex; }

	float RightSide() { return ex + 20; }

	float Top() { return ey; }

	float Bottom() { return ey + 20; }

	float ex = 0, ey = 0; // virsutinio kairiojo kampo koordinates
};
