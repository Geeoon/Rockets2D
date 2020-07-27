#include "ObjectBasic.h"

ObjectBasic::ObjectBasic(const Vector2& pos, long double m) {
	position = pos;
	mass = m;
}

void ObjectBasic::setOrientation(long double ori) {
	orientation = ori;
}

void ObjectBasic::setPosition(const Vector2& pos) {
	position = pos;
}

Vector2 ObjectBasic::getPosition() {
	return position;
}

void ObjectBasic::setCenterOfMass(const Vector2& com) {
	centerOfMass = com;
}

long double ObjectBasic::getMass() {
	return mass;
}

const Vector2& ObjectBasic::getCenterOfMass() {
	return centerOfMass;
}