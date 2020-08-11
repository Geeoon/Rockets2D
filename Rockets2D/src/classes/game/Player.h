#pragma once
#include <SFML/Graphics.hpp>
#include "Rocket/RocketParts/Engines/Engine.h"
#include "Rocket/RocketParts/Tanks/FuelTank.h"
#include "Rocket/Rocket.h"
#include "Object.h"

class Player
{
public:
	Player(sf::RenderTexture* t);
	void update();
	void draw();
	long double* getThrottlePtr();
	long double* getSteeringPtr();
private:
	sf::Clock clock;
	std::unique_ptr<Rocket> rocket;
	long double throttle = 0;
	long double steering = 0;
	void manageControls();
	sf::RenderTexture* texture = nullptr;
};