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

void Object::setMomentofInertia(long double moment) {
	momentOfInertia = moment;
}

void Object::applyForce(Vector2 v) {
	body.addForce(v);
}

void Object::applyForceRel(Vector2 v) {
	body.addForce(Vector2::constructFromPolar(v.getMagnitude(), v.getAngle() + orientation));
}

void Object::applyTorque(long double t) {
	torque = t; 
}

void Object::update() {
	elapsedTime = clock.getElapsedTime();
	clock.restart();
	angularVelocity += momentOfInertia * torque * elapsedTime.asSeconds() * timescale;
	orientation += angularVelocity * elapsedTime.asSeconds() * timescale;
	acceleration = Vector2(body.getNet().getX() / mass, body.getNet().getY() / mass);
	velocity += Vector2(acceleration.getX() * elapsedTime.asSeconds() * timescale, acceleration.getY() * elapsedTime.asSeconds() * timescale);
	position += Vector2(velocity.getX() * elapsedTime.asSeconds() * timescale, velocity.getY() * elapsedTime.asSeconds() * timescale);
	body = FreeBody();
	torque = 0;
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

long double Object::getMass() {
	return mass;
}