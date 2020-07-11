#pragma once
#include "math.h"

class Vector2
{
public:
	Vector2(long double xP, long double yP);
	long double getX();
	long double getY();
	Vector2 operator+=(const Vector2& v);
	Vector2 operator-=(const Vector2& v);
	Vector2 operator*=(long double multiplier);
	long double getMagnitude();
	long double getAngle();
private:
	long double x, y;
};

