#include "RocketPart.h"

RocketPart::RocketPart(sf::RenderTexture* t, const Vector2& pos, long double m) : ObjectBasic(pos, m){
	texture = t;
}

void RocketPart::setPosition(const Vector2& pos) {
	position = pos;
}

void RocketPart::setOrientation(long double ori) {
	orientation = ori;
}