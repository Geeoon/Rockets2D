#pragma once
#include "math.h"

class Vector2
{
public:
	Vector2(long double xP, long double yP);
	static Vector2 constructFromPolar(long double mag, long double dir) {
		return Vector2(mag * cosl(dir), mag * sinl(dir));
	}
	void normalize();
	long double getX();
	long double getY();
	long double getMagnitude();
	long double getAngle();
	Vector2 operator+=(const Vector2& v);
	Vector2 operator-=(const Vector2& v);
	Vector2 operator*=(long double multiplier);
	Vector2 operator+(const Vector2& right) const;
	Vector2 operator-(const Vector2& right) const;
	Vector2 operator*(const long double right) const;
	Vector2 operator/(const long double right) const;
	Vector2 operator-() const;
private:
	long double x, y;
};

