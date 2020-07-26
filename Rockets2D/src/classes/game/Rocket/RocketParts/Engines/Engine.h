#pragma once
#include "../RocketPart.h"

class Engine : public RocketPart
{
public:
	Engine(sf::RenderTexture* t, const Vector2& pos, long double m);
	virtual Vector2 update();
	virtual void draw();

protected:
	long double thrust; //thrust coefficient in vacuum
	long double gimbalAmount = 0;
	sf::ConvexShape nozzle;
	sf::RectangleShape throat;
	sf::RectangleShape base;
	sf::Color fillColor = sf::Color(0, 0, 0, 255);
	sf::Color borderColor = sf::Color(0, 255, 65);
};