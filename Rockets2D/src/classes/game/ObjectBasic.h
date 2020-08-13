#pragma once
#include "Vector2.h"
#define M_PI 3.14159265358979323851280895940618620443274267017841339111328125

//this class is exclusively used for rocket parts.
class ObjectBasic
{
public:
	ObjectBasic(const Vector2& pos, long double m);
	virtual void setOrientation(long double ori);
	void setPosition(const Vector2& pos);
	Vector2 getPosition();
	void setCenterOfMass(const Vector2& com);
	virtual long double getMass();
	Vector2 getCenterOfMass();
protected:
	Vector2 position = Vector2(0, 0);
	Vector2 centerOfMass = Vector2(0, 0);
	long double orientation = 0;
	long double mass = 0;
};