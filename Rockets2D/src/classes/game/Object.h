#pragma once
#include <SFML/Graphics.hpp>
#include <Box2D/box2d.h>
#include "FreeBody.h"

class Object
{
public:
	Object(sf::RenderTexture* t, long double xP, long double yP, long double m, long double r);
	void applyForce(Vector2 v);
	void update();
	void draw();
private:
	sf::Clock clock;
	sf::Time elapsedTime;
	FreeBody body = FreeBody();
	Vector2 position = Vector2(0, 0);
	Vector2 velocity = Vector2(0, 0);
	Vector2 acceleration = Vector2(0, 0);
	long double mass = 0; //kg
	long double radius = 0; //meters
	sf::RenderTexture* texture;
	sf::CircleShape shape;
	sf::Color borderColor;
	sf::Color innerColor;
};