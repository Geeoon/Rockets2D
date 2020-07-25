#pragma once
#include "Vector2.h"

//this class is exclusively used for rocket parts.
class ObjectBasic
{
public:
	ObjectBasic(const Vector2& pos, long double m);
	void setOrientation(long double ori);
	void setPosition(const Vector2& pos);
	void setCenterOfMass(const Vector2& com);
	const Vector2& getCenterOfMass();
protected:
	Vector2 position = Vector2(0, 0);
	Vector2 centerOfMass = Vector2(0, 0);
	long double orientation = 0;
	long double mass = 0;
};