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
	virtual void draw(const Vector2& pos, long double ori) override;

protected:
	//long double thrust = 7770000; //thrust coefficient in vacuum
	long double thrust = 10000; //test coeffiticient
	long double maxSteering = 0.523599;
	long double gimbalAmount = 0; //-50 - 50
	sf::ConvexShape nozzle;
	sf::ConvexShape flame;
	sf::RectangleShape throat;
	sf::RectangleShape base;
	sf::Color fillColor = sf::Color(0, 0, 0, 255);
	sf::Color borderColor = sf::Color(0, 255, 65);
};