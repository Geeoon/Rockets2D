#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/box2d.h>
#include "FreeBody.h"

class Object
{
public:
	Object(Vector2 pos, long double m);
	Object(Vector2 pos, long double m, Vector2 vel);
	void applyForce(Vector2 v);
	void applyTorque();
	void update();
	FreeBody& getFB();
	Vector2 getPosition();
	long double getOrientation();
	long double getMass();
private:
	sf::Clock clock;
	sf::Time elapsedTime;
	FreeBody body = FreeBody();
	Vector2 position = Vector2(0, 0);
	Vector2 velocity = Vector2(0, 0);
	Vector2 acceleration = Vector2(0, 0);
	long double angularVelocity = 0; //radians/second
	long double mass = 0; //kg
	long double orientation = 0; //radians
};