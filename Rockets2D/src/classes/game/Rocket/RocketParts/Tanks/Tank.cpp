#include "Tank.h"

Tank::Tank(sf::RenderTexture* t, const Vector2& rPos) : RocketPart(t, Vector2(0, 0)) {
	relativePosition = rPos;
	sprite.setOutlineColor(sf::Color(0, 255, 65));
	sprite.setOutlineThickness(0.3);
	sprite.setFillColor(sf::Color::Black);
	sprite.setSize(sf::Vector2f(3, 5));
	sprite.setOrigin(sprite.getLocalBounds().width / 2 - 0.3, sprite.getLocalBounds().height / 2 - 0.3);
	clock.restart();
}

Tank::Tank(sf::RenderTexture* t, const Vector2& rPos, long double rOri) : Tank(t, rPos) {
	relativeOrientation = rOri;
}

Vector2 Tank::update() {
	level -= burnRate * size * clock.getElapsedTime().asSeconds();
	long double additionalMass = (level / 100) * size;
	finalMass = mass + additionalMass;
	clock.restart();
	return Vector2(0, 0);
}

void Tank::draw() {
	RocketPart::draw();
	sprite.setRotation((float)((orientation + relativeOrientation) * 180 / M_PI));
	sprite.setPosition(outputPosition.toDrawSFV());
	texture->draw(sprite);
}

long double Tank::getMass() {
	return finalMass;
}