#pragma once
#include "../RocketPart.h"

class Engine : public RocketPart
{
public:
	Engine(sf::RenderTexture* t, const Vector2& pos, long double m);
	virtual void update(long double thrust);
	virtual void draw();

protected:
	sf::CircleShape nozzle;
	sf::RectangleShape throat;
	sf::RectangleShape base;
	long double thrust = 1; //thrust coefficient in vacuum
	sf::Color fillColor = sf::Color(0, 0, 0, 0);
	sf::Color borderColor = sf::Color(0, 255, 65);
};