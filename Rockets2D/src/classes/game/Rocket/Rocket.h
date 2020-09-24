#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../Object.h"
#include "RocketPartsManager.h"
#include "../ForcePosition.h"
#include "../Force.h"

class Rocket : public Object
{
public:
	Rocket(sf::RenderTexture* t, const Vector2& pos);
	Rocket(sf::RenderTexture* t, const Vector2& pos, long double ori);
	Rocket(sf::RenderTexture* t, const Vector2& pos, long double ori, const Vector2& vel);
	void update() override;
	void draw();
	void addPartManager(std::shared_ptr<RocketPartsManager> pM, const Vector2& relPos);
	void setThrottle(long double t);
	void setSteering(long double s);

private:
	long double throttle = 100;
	long double steering = 0;
	sf::RenderTexture* texture = nullptr;
	std::vector<std::shared_ptr<RocketPartsManager>> partManagers;
};