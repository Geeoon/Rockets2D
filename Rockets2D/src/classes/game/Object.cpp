#include "Object.h"

Object::Object(Vector2 pos, long double m) {
	position = pos;
	mass = m;
	clock.restart();
	elapsedTime = clock.getElapsedTime();
}

Object::Object(Vector2 pos, long double m, Vector2 vel) {
	position = pos;
	mass = m;
	velocity = vel;
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

FreeBody& Object::getFB() {
	return body;
}

Vector2 Object::getPosition() {
	return position;
}

long double Object::getOrientation() {
	return orientation;
}