#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"

class SpaceObject
{
public:
	SpaceObject(sf::RenderTexture* t, const Vector2& pos, long double m, long double r);
	SpaceObject(sf::RenderTexture* t, const Vector2& pos, long double m, long double r, const Vector2& vel);
	std::shared_ptr<Object> getObject();
	void draw();
	void update();

private:
	long double radius;
	bool collidable = true;
	std::shared_ptr<Object> obj;
	sf::RenderTexture* texture;
	sf::CircleShape shape;
	sf::Color borderColor;
	sf::Color innerColor;
};

