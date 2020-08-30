#pragma once
#include "../RocketPart.h"

class Tank : public RocketPart
{
public:
	Tank(sf::RenderTexture* t, const Vector2& rPos);
	Tank(sf::RenderTexture* t, const Vector2& rPos, long double rOri);
	virtual Vector2 update() override;
	virtual void draw() override;
	long double getMass() override;

public:
	sf::Clock clock;
	sf::RectangleShape sprite;
	long double finalMass = mass;
	long double level = 100; //goes from 100 - 0
	long double size = 10000; //kg
};