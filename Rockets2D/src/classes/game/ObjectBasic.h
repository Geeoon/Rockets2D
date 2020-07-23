#pragma once
#include "Vector2.h"

class ObjectBasic
{
public:
	ObjectBasic(const Vector2& pos, long double m);

protected:
	Vector2 position = Vector2(0, 0);
	long double orientation = 0;
	long double mass = 0;
};