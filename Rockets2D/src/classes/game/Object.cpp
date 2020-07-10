#include "Object.h"

Object::Object(sf::RenderTexture* t, double xP, double yP, double m, double r) {
	texture = t;
	x = xP;
	y = yP;
	mass = m;
	radius = r;
	shape.setRadius(radius);
	borderColor = sf::Color(0, 255, 65);
	innerColor = sf::Color(0, 0, 0, 0);
}

void Object::update() {
	texture->draw(shape);
}