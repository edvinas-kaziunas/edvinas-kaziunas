#include "Utils.h"
#include "Objects.h"

bool nmUtils::IsBetween(float val, float rangeB, float rangeE)
{
	return val > rangeB && val < rangeE;
}

bool nmUtils::Touching(Car &player, MovingObject &enemy)
{
	const bool betweenX = IsBetween(player.SpriteLeft(), enemy.SpriteLeft(), enemy.SpriteRight()) ||
		IsBetween(player.SpriteRight(), enemy.SpriteLeft(), enemy.SpriteRight());

	const bool betweenY = IsBetween(player.SpriteBottom(), enemy.SpriteTop(), enemy.SpriteBottom());

	return betweenX && betweenY;
}