#pragma once
#include <SFML/Graphics.hpp>
#include "../../ObjectBasic.h"

class RocketPart : public ObjectBasic
{
public:
	RocketPart(sf::RenderTexture* t, const Vector2& pos, long double m);
	void setPosition(const Vector2& pos);
	void setOrientation(long double ori);
	virtual void update(long double thrust) = 0; //pure virtual functions
	virtual void draw() = 0;

protected:
	sf::RenderTexture* texture = nullptr;
	long double thrust = 0;
};

