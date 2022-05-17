#pragma once

class Car;
class Movement;

namespace nmUtils
{
	bool IsBetween(float val, float rangeB, float rangeE);
	bool InOnPlate(Car &player, Movement &enemy);
}
