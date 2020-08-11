#include "RocketPart.h"

RocketPart::RocketPart(sf::RenderTexture* t, const Vector2& pos) : ObjectBasic(pos, 0) {
	texture = t;
}

RocketPart::RocketPart(sf::RenderTexture* t, const Vector2& pos, long double rOri) : ObjectBasic(pos, 0) {
	texture = t;
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
	std::cout << "drawing generic part";
}