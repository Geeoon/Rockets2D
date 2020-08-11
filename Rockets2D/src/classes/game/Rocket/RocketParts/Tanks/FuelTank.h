#pragma once
#include "../RocketPart.h"

class FuelTank : public RocketPart
{
public:
	FuelTank(sf::RenderTexture* t, const Vector2& rPos);
	FuelTank(sf::RenderTexture* t, const Vector2& rPos, long double rOri);
	virtual Vector2 update() override;
	virtual void draw() override;
	
public:
	sf::Clock clock;
	sf::RectangleShape sprite;
	long double finalMass = mass;
	long double fuelLevel = 100; //goes from 100 - 0
	long double fuelSize = 10000; //kg
};