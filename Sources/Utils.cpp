#include "Utils.h"
#include "Objects.h"

bool nmUtils::IsBetween(float val, float rangeB, float rangeE)
{
	return val > rangeB && val < rangeE;
}

bool nmUtils::InOnPlate(Car &player, Movement &enemy)
{
	const bool betweenX = IsBetween(player.LeftSide(), enemy.LeftSide(), enemy.RightSide()) ||
		IsBetween(player.RightSide(), enemy.LeftSide(), enemy.RightSide());

	const bool betweenY = IsBetween(player.Bottom(), enemy.Top(), enemy.Bottom());

	return betweenX && betweenY;
}