#pragma once

class Car;
class MovingObject;

namespace nmUtils
{
	bool IsBetween(float val, float rangeB, float rangeE);
	bool InOnPlate(Car &player, MovingObject &enemy);
}
