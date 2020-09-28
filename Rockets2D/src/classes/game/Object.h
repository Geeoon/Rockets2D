#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "FreeBody.h"

class Object
{
public:
	Object(const Vector2& pos, long double m);
	Object(const Vector2& pos, long double m, const Vector2& vel);
	void setMomentofInertia(long double moment);
	void applyForce(const Vector2& v);
	void applyForceRel(Vector2 v); //applies force relative to the object's orientation
	void applyTorque(long double t); //facing back (same direction as eyes are facing when looking at a monitor
	virtual void update();
	FreeBody* getFBPtr();
	virtual Vector2 getPosition();
	long double getOrientation();
	long double getMass();
	void resetTime();
	virtual void draw();

protected:
	sf::Clock clock;
	sf::Time elapsedTime;
	FreeBody body = FreeBody();
	Vector2 position = Vector2(0, 0);
	Vector2 velocity = Vector2(0, 0);
	Vector2 acceleration = Vector2(0, 0);
	Vector2 centerOfMass = Vector2(0, 0);
	long double momentOfInertia = 1;
	long double timescale = 1;
	long double angularAcceleration = 0; //radians / second ^ 2
	long double angularVelocity = 0; //radians/second
	long double mass = 0; //kg
	long double orientation = 0; //radians
	long double torque = 0;
};