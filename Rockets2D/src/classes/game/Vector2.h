#pragma once
#include <SFML/Graphics.hpp>
#include "math.h"

class Vector2
{
public:
	Vector2(long double xP, long double yP);
	Vector2(long double xP, long double yP, bool push);
	static Vector2 constructFromPolar(long double mag, long double dir) {
		return Vector2(mag * cosl(dir), mag * sinl(dir));
	}
	void normalize();
	long double getX() const;
	long double getY() const;
	long double* getXPointer();
	long double* getYPointer();
	long double getMagnitude() const;
	long double getAngle() const;
	virtual bool getIsPush();
	Vector2& operator+=(const Vector2& v);
	Vector2& operator-=(const Vector2& v);
	Vector2& operator*=(long double multiplier);
	Vector2 operator+(const Vector2& right) const;
	Vector2 operator-(const Vector2& right) const;
	Vector2 operator*(const long double right) const;
	Vector2 operator/(const long double right) const;
	Vector2 operator-() const;
	sf::Vector2f toSF2f() const;
	sf::Vector2f toDrawSFV() const;
protected:
	long double x, y;
	bool isPush = false;
};

