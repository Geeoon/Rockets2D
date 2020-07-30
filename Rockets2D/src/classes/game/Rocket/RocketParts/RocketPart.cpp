#include "RocketPart.h"

RocketPart::RocketPart(sf::RenderTexture* t, const Vector2& pos) : ObjectBasic(pos, 0){
	texture = t;
}

void RocketPart::setThrottle(long double t) {
	throttle = t;
}

void RocketPart::setRelativePosition(Vector2 rPos) {
	relativePosition = rPos;
}

void RocketPart::setRelativeOrientation(long double rOri) {
	relativeOrientation = rOri;
}

Vector2 RocketPart::update() {
	return Vector2(0, 0);
}

void RocketPart::draw() {
	std::cout << "drawing generic part";
}