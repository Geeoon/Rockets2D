#include "SpaceObject.h"

SpaceObject::SpaceObject(sf::RenderTexture* t, const Vector2& pos, long double m, long double r) : Object(pos, m) {
	//texture, position, mass, radius
	texture = t;
	radius = r;
	shape.setRadius((float)r);
	borderColor = sf::Color(0, 255, 65);
	innerColor = sf::Color(0, 0, 255, 0);
	shape.setPointCount(500);
	shape.setFillColor(innerColor);
	shape.setOutlineColor(borderColor);
	shape.setOutlineThickness(3);
	shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2);
}

SpaceObject::SpaceObject(sf::RenderTexture* t, const Vector2& pos, long double m, long double r, const Vector2& vel) : Object(pos, m, vel) {
	//texture, position, mass, radius, velocity
	texture = t;
	radius = r;
	shape.setRadius((float)r);
	borderColor = sf::Color(0, 255, 65);
	innerColor = sf::Color(0, 0, 255, 0);
	shape.setPointCount(500);
	shape.setFillColor(innerColor);
	shape.setOutlineColor(borderColor);
	shape.setOutlineThickness(3);
	shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2);
}

void SpaceObject::draw() {
	shape.setPosition((float)position.getX(), -(float)position.getY());
	shape.setOutlineThickness((3 * texture->getView().getSize().x / texture->getSize().x < 1) ? 1 : (3 * texture->getView().getSize().x / texture->getSize().x));
	shape.setRotation((float)orientation);
	texture->draw(shape);
}