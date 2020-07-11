#include "Vector2.h"

Vector2::Vector2(long double xP, long double yP) {
	x = xP;
	y = yP;
}

long double Vector2::getX() {
	return x;
}

long double Vector2::getY() {
	return y;
}

Vector2 Vector2::operator+=(const Vector2& v) {
	x += v.x;
	y += v.y;
	return *this;
}

Vector2 Vector2::operator-=(const Vector2& v) {
	x -= v.x;
	y -= v.y;
	return *this;
}

Vector2 Vector2::operator*=(const long double multiplier) {
	x *= multiplier;
	y *= multiplier;
	return *this;
}

long double Vector2::getMagnitude() {
	return sqrt(x*x + y*y);
}

long double Vector2::getAngle() {
	return atan2(y, x);
}