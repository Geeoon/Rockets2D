#include "Engine.h"
//this base rocket is based on the F-1 Engine
Engine::Engine(sf::RenderTexture* t, const Vector2& rPos) : RocketPart(t, Vector2(0, 0)) {//1 pixel = 1 meter for reference
	name = "F-1 Engine";
	description = "A classic engine used in the Saturn V rocket.";
	mass = 8400;//dry mass AKA mass at 0 throttle.
	relativePosition = rPos;
	throttle = 0;
	nozzle.setPointCount(3);
	nozzle.setPoint(0, sf::Vector2f(0.0f, 0.0f));
	nozzle.setPoint(1, sf::Vector2f(-1.859f, 4.229f));
	nozzle.setPoint(2, sf::Vector2f(1.859f, 4.229f));
	nozzle.setFillColor(fillColor);
	nozzle.setOutlineColor(borderColor);
	nozzle.setOutlineThickness(0.3f);
	nozzle.setOrigin(sf::Vector2f(0.0f, -0.97f));
	nozzle.setPosition(sf::Vector2f(0.0f, 0.0f));

	flame.setPointCount(3);
	flame.setPoint(0, sf::Vector2f(-1.859f, 0.0f));
	flame.setPoint(1, sf::Vector2f(1.859f, 0.0f));
	flame.setPoint(2, sf::Vector2f(0.0f, 0.0f));
	flame.setFillColor(fillColor);
	flame.setOutlineColor(borderColor);
	flame.setOutlineThickness(0.3f);
	flame.setOrigin(sf::Vector2f(0.0f, -5.5f));
	flame.setPosition(sf::Vector2f(0.0f, 0.0f));

	throat.setFillColor(fillColor);
	throat.setOutlineColor(borderColor);
	throat.setOutlineThickness(0.3f);
	throat.setSize(sf::Vector2f(0.5f, 0.8f));
	throat.setOrigin((float)((throat.getLocalBounds().width - 0.6) / 2), (float)((throat.getLocalBounds().height - 0.6) / 2 - 1));
	throat.setPosition(sf::Vector2f(0.0f, 0.0f));
	

	base.setFillColor(fillColor);
	base.setOutlineColor(borderColor);
	base.setOutlineThickness(0.3f);
	base.setSize(sf::Vector2f(3.0f, 1.0f));
	base.setOrigin((float)(base.getLocalBounds().width - 0.6) / 2, (float)(base.getLocalBounds().height - 0.6) / 2);
	base.setPosition(sf::Vector2f(0.0f, 0.0f));
}

Engine::Engine(sf::RenderTexture* t, const Vector2& rPos, long double rOri) : Engine(t, rPos) {//1 pixel = 1 meter for reference
	relativeOrientation = rOri;
}

Vector2 Engine::update() {
	gimbalAmount = -((long double)((long double)steering / (long double)50) * maxSteering);
	Vector2 output = Vector2::constructFromPolar(thrust * throttle, -orientation - relativeOrientation + gimbalAmount + (long double)0.78539816339 * (long double)2);
	return Vector2(output.getX(), output.getY(), true);
}

void Engine::draw() {
	RocketPart::draw();
	flame.setPoint(2, sf::Vector2f(0.0f, (float)throttle / 5));
	nozzle.setRotation((float)((orientation + relativeOrientation - gimbalAmount) * (long double)180 / (long double)M_PI));
	throat.setRotation((float)((orientation + relativeOrientation - gimbalAmount) * (long double)180 / (long double)M_PI));
	base.setRotation((float)((orientation + relativeOrientation) * (long double)180 / (long double)M_PI));
	flame.setRotation((float)((orientation + relativeOrientation - gimbalAmount) * (long double)180 / (long double)M_PI));

	nozzle.setPosition(outputPosition.toDrawSFV());
	throat.setPosition(outputPosition.toDrawSFV());
	base.setPosition(outputPosition.toDrawSFV());
	flame.setPosition(outputPosition.toDrawSFV());
	texture->draw(nozzle);
	texture->draw(throat);
	texture->draw(base);
	texture->draw(flame);
}