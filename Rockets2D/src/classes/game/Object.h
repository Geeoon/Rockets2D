#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/box2d.h>
#include <iostream>

class Object
{
public:
	Object(sf::RenderTexture* t, double xP, double yP, double m, double r);
	void update();
	void draw();
private:
	double x = 0;
	double y = 0;
	double mass = 0; //kg
	double radius = 0; //meters
	sf::RenderTexture* texture;
	sf::CircleShape shape;
	sf::Color borderColor;
	sf::Color innerColor;
};