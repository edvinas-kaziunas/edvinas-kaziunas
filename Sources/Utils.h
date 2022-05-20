#pragma once

class Car;
class MovingObject;

namespace nmUtils
{
	bool IsBetween(float val, float rangeB, float rangeE);
	bool Touching(Car &player, MovingObject &enemy);
}
