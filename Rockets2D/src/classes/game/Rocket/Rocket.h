#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "RocketParts/RocketPart.h"

class Rocket
{
public:
	Rocket(sf::RenderTexture* t);
	void update();
	void draw();
	void addPart(const RocketPart& p);



private:
	long double throttle = 0;
	sf::RenderTexture* texture;
};