#pragma once
#include <SFML/Graphics.hpp>
#include <functional>
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
	void setSyncUpdates(std::vector<std::function<void()>>* fv);
	long double* getThrottlePtr();
	long double* getSteeringPtr();
	std::shared_ptr<Rocket> getRocketPtr();
private:
	sf::Clock clock;
	std::shared_ptr<Rocket> rocket;
	std::vector<std::function<void()>>* syncUpdateVect;
	long double throttle = 0;
	long double steering = 0;
	void manageControls();
	sf::RenderTexture* texture = nullptr;
};