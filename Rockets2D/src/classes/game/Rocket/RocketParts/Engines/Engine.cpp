#include "Engine.h"

Engine::Engine(sf::RenderTexture* t, const Vector2& pos, long double m) : RocketPart(t, pos, m) {
	mass = 10;
	thrust = 1;
	nozzle.setFillColor(fillColor);
	nozzle.setOutlineColor(borderColor);
	nozzle.setOutlineThickness(3);
	nozzle.setPointCount(3);
	nozzle.setRadius(5);

	throat.setFillColor(fillColor);
	throat.setOutlineColor(borderColor);
	throat.setOutlineThickness(3);
	throat.setSize(sf::Vector2f(2, 2));
	base.setFillColor(fillColor);
	base.setOutlineColor(borderColor);
	base.setOutlineThickness(3);
	throat.setSize(sf::Vector2f(2, 2));
}

Vector2& Engine::update() {
	Vector2 force(0, 0);
	force = Vector2(0, thrust * throttle);
	return force;
}

void Engine::draw() {
	texture->draw(nozzle);
	texture->draw(throat);
	texture->draw(base);
}