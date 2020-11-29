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
	Rocket(std::string ti, std::string d, sf::RenderTexture* t, const Vector2& pos);
	Rocket(std::string ti, std::string d, sf::RenderTexture* t, const Vector2& pos, long double ori);
	Rocket(std::string ti, std::string d, sf::RenderTexture* t, const Vector2& pos, long double ori, const Vector2& vel);
	void update() override;
	void draw() override;
	void drawAtPNR(const Vector2& p, long double r);
	void addPartManager(std::shared_ptr<RocketPartsManager> pM, const Vector2& relPos);
	void setThrottle(long double t);
	void setSteering(long double s);
	Vector2& getPosition() override;

private:
	long double throttle = 0;
	long double steering = 50;
	sf::RenderTexture* texture = nullptr;
	std::vector<std::shared_ptr<RocketPartsManager>> partManagers;
};