#include "Engine.h"
//this base rocket is based on the F-1 Engine
Engine::Engine(sf::RenderTexture* t, const Vector2& rPos) : RocketPart(t, Vector2(0, 0)) {//1 pixel = 1 meter for reference
	name = "F-1 Engine";
	description = "A classic engine used in the Saturn V rocket.";
	mass = 8390;//dry mass AKA mass at 0 throttle.
	relativePosition = rPos;
	throttle = 0;
	nozzle.setPointCount(3);
	nozzle.setPoint(0, sf::Vector2f(0, 0));
	nozzle.setPoint(1, sf::Vector2f(-1.859, 4.229));
	nozzle.setPoint(2, sf::Vector2f(1.859, 4.229));
	nozzle.setFillColor(fillColor);
	nozzle.setOutlineColor(borderColor);
	nozzle.setOutlineThickness(0.3);
	nozzle.setOrigin(sf::Vector2f(0, -0.97));
	nozzle.setPosition(sf::Vector2f(0, 0));

	flame.setPointCount(3);
	flame.setPoint(0, sf::Vector2f(-1.859, 0));
	flame.setPoint(1, sf::Vector2f(1.859, 0));
	flame.setPoint(2, sf::Vector2f(0, 0));
	flame.setFillColor(fillColor);
	flame.setOutlineColor(borderColor);
	flame.setOutlineThickness(0.3);
	flame.setOrigin(sf::Vector2f(0, -5.5));
	flame.setPosition(sf::Vector2f(0, 0));

	throat.setFillColor(fillColor);
	throat.setOutlineColor(borderColor);
	throat.setOutlineThickness(0.3);
	throat.setSize(sf::Vector2f(0.5, 0.8));
	throat.setOrigin((throat.getLocalBounds().width - 0.6) / 2, (throat.getLocalBounds().height - 0.6) / 2 - 1);
	throat.setPosition(sf::Vector2f(0, 0));
	

	base.setFillColor(fillColor);
	base.setOutlineColor(borderColor);
	base.setOutlineThickness(0.3);
	base.setSize(sf::Vector2f(3, 1));
	base.setOrigin((base.getLocalBounds().width - 0.6) / 2, (base.getLocalBounds().height - 0.6) / 2);
	base.setPosition(sf::Vector2f(0, 0));
}

Engine::Engine(sf::RenderTexture* t, const Vector2& rPos, long double rOri) : Engine(t, rPos) {//1 pixel = 1 meter for reference
	relativeOrientation = rOri;
}

Vector2 Engine::update() {
	gimbalAmount = -((long double)(steering / 50) * maxSteering);
	return Vector2::constructFromPolar(thrust * throttle, orientation + relativeOrientation + gimbalAmount + 0.78539816339 * 2);
}

void Engine::draw() {
	RocketPart::draw();
	flame.setPoint(2, sf::Vector2f(0, throttle / 5));
	nozzle.setRotation((float)((orientation + relativeOrientation - gimbalAmount) * 180 / M_PI));
	throat.setRotation((float)((orientation + relativeOrientation - gimbalAmount) * 180 / M_PI));
	base.setRotation((float)((orientation + relativeOrientation) * 180 / M_PI));
	flame.setRotation((float)((orientation + relativeOrientation - gimbalAmount) * 180 / M_PI));

	nozzle.setPosition(outputPosition.toDrawSF2f());
	throat.setPosition(outputPosition.toDrawSF2f());
	base.setPosition(outputPosition.toDrawSF2f());
	flame.setPosition(outputPosition.toDrawSF2f());
	texture->draw(nozzle);
	texture->draw(throat);
	texture->draw(base);
	texture->draw(flame);
}