#pragma once
#include <SFML/Graphics.hpp>
#include "../../ObjectBasic.h"

class RocketPart : public ObjectBasic
{
public:
	RocketPart(sf::RenderTexture* t, const Vector2& pos, long double m);
	void setThrottle(long double t);
	virtual Vector2 update() = 0; //pure virtual functions
	virtual void draw() = 0;

protected:
	sf::RenderTexture* texture = nullptr;
	long double throttle = 0;
};

