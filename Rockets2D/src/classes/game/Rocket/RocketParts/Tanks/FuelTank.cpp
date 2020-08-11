#include "FuelTank.h"

FuelTank::FuelTank(sf::RenderTexture* t, const Vector2& rPos) : RocketPart(t, Vector2(0, 0)) {
	relativePosition = rPos;
	sprite.setOutlineColor(sf::Color(0, 255, 65));
	sprite.setOutlineThickness(0.3);
	sprite.setFillColor(sf::Color::Black);
	sprite.setSize(sf::Vector2f(3, 5));
	sprite.setOrigin(sprite.getLocalBounds().width / 2 - 0.3, sprite.getLocalBounds().height / 2 - 0.3);
	clock.restart();
}

FuelTank::FuelTank(sf::RenderTexture* t, const Vector2& rPos, long double rOri) : FuelTank(t, rPos) {
	relativeOrientation = rOri;
}

Vector2 FuelTank::update() {
	fuelLevel -= burnRate * fuelSize * clock.getElapsedTime().asSeconds();
	long double additionalMass = (fuelLevel / 100) * fuelSize;
	finalMass = mass + additionalMass;
	clock.restart();
	return Vector2(0, 0);
}

void FuelTank::draw() {
	sprite.setRotation((float)((orientation + relativeOrientation) * 180 / M_PI));
	outputPosition = Vector2((float)(position.getX() + relativePosition.getX() * cosl(orientation) - relativePosition.getY() * sinl(orientation)), -(float)(position.getY() + relativePosition.getX() * sinl(orientation) + relativePosition.getY() * cosl(orientation)));
	sprite.setPosition(outputPosition.toSF2f());
	texture->draw(sprite);
}