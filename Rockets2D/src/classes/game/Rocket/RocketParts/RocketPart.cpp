#include "RocketPart.h"

RocketPart::RocketPart(sf::RenderTexture* t, const Vector2& pos, long double m) : ObjectBasic(pos, m){
	texture = t;
}

void RocketPart::setThrottle(long double t) {
	throttle = t;
}