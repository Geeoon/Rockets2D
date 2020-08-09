#pragma once
#include "../RocketPart.h"
#include <iostream>

class Engine : public RocketPart
{
public:
	Engine(sf::RenderTexture* t, const Vector2& rPos);
	Engine(sf::RenderTexture* t, const Vector2& rPos, long double rOri);
	virtual Vector2 update() override;
	virtual void draw() override;

protected:
	long double thrust = 1; //thrust coefficient in vacuum
	long double gimbalAmount = 0;
	sf::ConvexShape nozzle;
	sf::ConvexShape flame;
	sf::RectangleShape throat;
	sf::RectangleShape base;
	sf::Color fillColor = sf::Color(0, 0, 0, 255);
	sf::Color borderColor = sf::Color(0, 255, 65);
};