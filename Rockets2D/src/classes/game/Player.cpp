#include "Player.h"

Player::Player(sf::RenderTexture* t) {
	texture = t;
	obj = std::make_shared<Object>(Vector2(0, 0), 100);
	obj->setMomentofInertia((obj->getMass() / 12) * (pow(dimentions.getX(), 2), pow(dimentions.getY(), 2)));

	sf::Color borderColor = sf::Color(0, 255, 65);
	sf::Color innerColor = sf::Color(0, 0, 255);
	sprite.setSize(sf::Vector2f((float)dimentions.getX(), (float)dimentions.getY()));
	sprite.setFillColor(innerColor);
	sprite.setOutlineColor(borderColor);
	sprite.setOutlineThickness(3);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setPosition(sf::Vector2f(0, 0));
}

void Player::update() {
	manageControls();
	obj->update();
}

void Player::draw() {
	sprite.setPosition((float)obj->getPosition().getX(), -(float)obj->getPosition().getY());
	sprite.setRotation((float)(obj->getOrientation() * 180 / 3.1415926535));
	texture->draw(sprite);
}

std::shared_ptr<Object> Player::getObj() {
	return obj;
}

void Player::manageControls() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		obj->applyForceRel(Vector2(0, 1000));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		obj->applyForceRel(Vector2(0, -1000));
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		obj->applyTorque(-0.00001);
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		obj->applyTorque(0.00001);
	}
}