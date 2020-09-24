#include "Vector2.h"

Vector2::Vector2(long double xP, long double yP) {
	x = xP;
	y = yP;
}

void Vector2::normalize() {
	x = (*this / this->getMagnitude()).x;
	y = (*this / this->getMagnitude()).y;
}

long double Vector2::getX() const {
	return x;
}

long double Vector2::getY() const {
	return y;
}

long double Vector2::getMagnitude() const {
	return sqrt(x * x + y * y);
}

long double Vector2::getAngle() const {
	return atan2(y, x);
}

bool Vector2::getIsPush() const {
	return false;
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

Vector2 Vector2::operator+(const Vector2& right) const {
	return Vector2(x + right.x, y + right.y);
}

Vector2 Vector2::operator-(const Vector2& right) const {
	return Vector2(x - right.x, y - right.y);
}

Vector2 Vector2::operator*(const long double right) const {
	return Vector2(x * right, y * right);
}
Vector2 Vector2::operator/(const long double right) const {
	return Vector2(x / right, y / right);
}

Vector2 Vector2::operator-() const {
	return Vector2(-x, -y);
}

sf::Vector2f Vector2::toSF2f() const {
	return sf::Vector2f(x, y);
}

sf::Vector2f Vector2::toDrawSFV() const {
	return sf::Vector2f(x, -y);
}