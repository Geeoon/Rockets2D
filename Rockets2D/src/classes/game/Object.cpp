#include "Object.h"

Object::Object(sf::RenderTexture* t, long double xP, long double yP, long double m, long double r) {
	texture = t;
	position = Vector2(xP, yP);
	mass = m;
	radius = r;
	shape.setRadius(radius);
	borderColor = sf::Color(0, 255, 65);
	innerColor = sf::Color(0, 0, 255, 0);
	shape.setPointCount(500);
	shape.setFillColor(innerColor);
	shape.setOutlineColor(borderColor);
	shape.setOutlineThickness(3);
	shape.setOrigin(shape.getLocalBounds().width / 2, shape.getLocalBounds().height / 2);
	clock.restart();
	elapsedTime = clock.getElapsedTime();
}

void Object::applyForce(Vector2 v) {
	body.addForce(v);
}

void Object::applyTorque() {

}

void Object::update() {
	elapsedTime = clock.getElapsedTime();
	clock.restart();
	acceleration = Vector2(body.getNet().getX() / mass, body.getNet().getY() / mass);
	velocity += Vector2(acceleration.getX() * elapsedTime.asSeconds(), acceleration.getY() * elapsedTime.asSeconds());
	position += Vector2(velocity.getX() * elapsedTime.asSeconds(), velocity.getY() * elapsedTime.asSeconds());
	body = FreeBody();
}

void Object::draw() {
	shape.setPosition(position.getX(), -position.getY());
	shape.setOutlineThickness((3 * texture->getView().getSize().x / texture->getSize().x < 1) ? 1 : (3 * texture->getView().getSize().x / texture->getSize().x));
	shape.setRotation(orientation);
	texture->draw(shape);
}

FreeBody& Object::getFB() {
	return body;
}