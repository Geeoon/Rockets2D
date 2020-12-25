#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"

class SpaceObject : public Object
{
public:
	SpaceObject(std::string ti, std::string d, sf::RenderTexture* t, const Vector2& pos, long double m, long double r);
	SpaceObject(std::string ti, std::string d, sf::RenderTexture* t, const Vector2& pos, long double m, long double r, const Vector2& vel);
	void draw() override;
	void draw(const Vector2& p, long double r) override;

private:
	bool collidable = true;
	float offsetX{};
	float offsetY{};
	sf::RenderTexture* texture{};
	sf::CircleShape shape;
	sf::Color borderColor;
	sf::Color innerColor;
};

