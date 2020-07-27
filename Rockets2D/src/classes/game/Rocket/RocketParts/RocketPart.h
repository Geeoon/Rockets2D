#pragma once
#include <SFML/Graphics.hpp>
#include "../../ObjectBasic.h"

class RocketPart : public ObjectBasic
{
public:
	RocketPart(sf::RenderTexture* t, const Vector2& pos, long double m);
	void setThrottle(long double t);
	virtual void setRelativePosition(Vector2 rPos);
	virtual void setRelativeOrientation(long double rOri);
	virtual Vector2 update(); //pure virtual functions
	virtual void draw();

protected:
	sf::RenderTexture* texture = nullptr;
	long double throttle = 0;
	Vector2 relativePosition = Vector2(0, 0);
	long double relativeOrientation = 0;
};

