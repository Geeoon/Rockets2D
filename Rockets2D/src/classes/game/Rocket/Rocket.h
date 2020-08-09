#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "../Object.h"
#include "RocketPartsManager.h"
#include "../ForcePosition.h"

class Rocket : public Object
{
public:
	Rocket(sf::RenderTexture* t, const Vector2& pos);
	Rocket(sf::RenderTexture* t, const Vector2& pos, long double ori);
	Rocket(sf::RenderTexture* t, const Vector2& pos, long double ori, const Vector2& vel);
	void update() override;
	void draw();
	void addPartManager(const RocketPartsManager& pM, const Vector2& relPos);
	void setThrottle(long double t);

private:
	long double throttle = 100;
	sf::RenderTexture* texture = nullptr;
	std::vector<RocketPartsManager> partManagers;
};