#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "FreeBody.h"

class Object
{
public:
	Object(std::string t, std::string d, const Vector2& pos, long double m, long double r);
	Object(std::string t, std::string d, const Vector2& pos, long double m, long double r, const Vector2& vel);
	~Object()								= default;
	Object(const Object&)					= default;
	Object& operator=(const Object&)		= default;
	Object(Object&&)						= default;
	Object& operator=(Object&&)				= default;
	void setMomentofInertia(long double moment);
	void applyForce(const Vector2& v);
	void applyForceRel(Vector2 v); //applies force relative to the object's orientation
	void applyTorque(long double t); //facing back (same direction as eyes are facing when looking at a monitor
	virtual void update();
	FreeBody* getFBPtr();
	virtual Vector2& getPosition();
	long double getOrientation();
	long double* getOrientationPTR();
	long double getMass();
	void resetTime();
	virtual void draw();
	virtual void draw(const Vector2& p, long double r);
	virtual void setPosition(const Vector2& pos);
	std::string getTitle();
	std::string getDescription();
	long double getAngularVelocity();
	long double getRadius();

protected:
	long double radius;
	sf::Clock clock;
	std::string title;
	std::string description;
	sf::Time elapsedTime;
	FreeBody body = FreeBody();
	Vector2 position = Vector2(0, 0);
	Vector2 velocity = Vector2(0, 0);
	Vector2 acceleration = Vector2(0, 0);
	Vector2 centerOfMass = Vector2(0, 0);
	long double momentOfInertia = 1;
	long double timescale = /*100000*/1;
	long double angularAcceleration = 0; //radians / second ^ 2
	long double angularVelocity = 0; //radians/second
	long double mass = 0; //kg
	long double orientation = 0; //radians
	long double torque = 0;
};