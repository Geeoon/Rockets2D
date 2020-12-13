#include "RocketPart.h"

RocketPart::RocketPart(sf::RenderTexture* t, const Vector2& pos) : ObjectBasic(pos, 0) {
	texture = t;
}

RocketPart::RocketPart(sf::RenderTexture* t, const Vector2& pos, long double rOri) : RocketPart(t, pos) {
	relativeOrientation = rOri;
}

void RocketPart::setThrottle(long double t) {
	throttle = t;
}

void RocketPart::setSteering(long double s) {
	steering = s;
}

void RocketPart::setOrientation(long double ori) {
	orientation = ori;
}

void RocketPart::setBurnRate(long double br) {
	burnRate = br;
}

void RocketPart::setRelativePosition(Vector2 rPos) {
	relativePosition = rPos;
}

void RocketPart::setRelativeOrientation(long double rOri) {
	relativeOrientation = rOri;
}

Vector2 RocketPart::getRelativePosition() {
	return relativePosition;
}

Vector2 RocketPart::update() {
	return Vector2(0, 0);
}

void RocketPart::draw() {
	outputPosition = Vector2((long double)(position.getX() + relativePosition.getX() * cosl(orientation) - relativePosition.getY() * sinl(orientation)), (long double)(position.getY() - (relativePosition.getX() * sinl(orientation) + relativePosition.getY() * cosl(orientation))));
}

void RocketPart::draw(const Vector2& p, long double r) {
	outputPosition = Vector2((long double)(p.getX() + relativePosition.getX() * cosl(r) - relativePosition.getY() * sinl(r)), (long double)(p.getY() - (relativePosition.getX() * sinl(r) + relativePosition.getY() * cosl(r))));
}