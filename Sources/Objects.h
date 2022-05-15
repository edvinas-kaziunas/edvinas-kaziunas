#pragma once

#include "Defines.h"

struct Player
{
	float LegsStartX() { return x + 24; }

	float LegsEndX() { return x + 64; }

	float LegsY() { return y + 73; }

	float x = 0, y = 0; // virsutinio kairiojo kampo koordinates
};

struct Plate
{
	float StartX() { return x; }

	float EndX() { return x + PLATES_WIDTH; }

	float TopY() { return y; }

	float BottomY() { return y + PLATES_HEIGHT; }

	float x = 0, y = 0; // virsutinio kairiojo kampo koordinates
};
