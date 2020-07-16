#include "SpaceObject.h"

SpaceObject::SpaceObject(sf::RenderTexture* t, Vector2 pos, long double m, long double r) {
	//texture, position, mass, radius
	texture = t;
	radius = r;
	obj = std::make_unique<Object>(pos, m);
	shape.setRadius(r);
	borderColor = sf::Color(0, 255, 65);
	innerColor = sf::Color(0, 0, 255, 0);
	shape.setPointCount(500);
	shape.setFillColor(innerColor);
	shape.setOutlineColor(borderColor);
	shape.setOutlineThickness(3);
	shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2);
}

SpaceObject::SpaceObject(sf::RenderTexture* t, Vector2 pos, long double m, long double r, Vector2 vel) {
	//texture, position, mass, radius, velocity
	texture = t;
	obj = std::make_unique<Object>(pos, m, vel);
	radius = r;
	shape.setRadius(r);
	borderColor = sf::Color(0, 255, 65);
	innerColor = sf::Color(0, 0, 255, 0);
	shape.setPointCount(500);
	shape.setFillColor(innerColor);
	shape.setOutlineColor(borderColor);
	shape.setOutlineThickness(3);
	shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2);
}

std::shared_ptr<Object> SpaceObject::getObject() {
	return obj;
}
void SpaceObject::draw() {
	shape.setPosition(obj->getPosition().getX(), -obj->getPosition().getY());
	shape.setOutlineThickness((3 * texture->getView().getSize().x / texture->getSize().x < 1) ? 1 : (3 * texture->getView().getSize().x / texture->getSize().x));
	shape.setRotation(obj->getOrientation());
	texture->draw(shape);
}

void SpaceObject::update() {
	obj->update();
}