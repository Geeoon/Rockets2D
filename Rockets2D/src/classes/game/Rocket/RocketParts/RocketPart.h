#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "../../ObjectBasic.h"

class RocketPart : public ObjectBasic
{
public:
	RocketPart(sf::RenderTexture* t, const Vector2& pos);
	RocketPart(sf::RenderTexture* t, const Vector2& pos, long double rOri);
	void setThrottle(long double t);
	void setSteering(long double s);
	void setOrientation(long double ori);
	void setBurnRate(long double br);
	virtual void setRelativePosition(Vector2 rPos);
	virtual void setRelativeOrientation(long double rOri);
	Vector2 getRelativePosition();
	virtual Vector2 update();
	virtual void draw();
	virtual void drawAtPNR(const Vector2& p, long double r);

protected:
	std::string name = "Generic Part";
	std::string description = "Generic description.";
	sf::RenderTexture* texture = nullptr;
	long double throttle = 0;
	long double steering = 0;
	long double burnRate = 0; //for fuel and oxidizer
	Vector2 relativePosition = Vector2(0, 0);
	long double relativeOrientation = 0;
	Vector2 outputPosition = Vector2(0, 0);
};

