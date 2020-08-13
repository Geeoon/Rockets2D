#include "Player.h"

Player::Player(sf::RenderTexture* t) {
	texture = t;
	rocket = std::make_unique<Rocket>(texture, Vector2(0, 0));
	std::shared_ptr<RocketPartsManager>rktMan = std::make_shared<RocketPartsManager>();
	rktMan->addPart(std::make_shared<Engine>(texture, Vector2(0, 0), 0));
	rktMan->addPart(std::make_shared<FuelTank>(texture, Vector2(0, 3.2)));
	
	/*std::shared_ptr<RocketPartsManager>rktMan2 = std::make_shared<RocketPartsManager>();
	rktMan2->addPart(std::make_shared<Engine>(texture, Vector2(50, 0), 0));
	rktMan2->addPart(std::make_shared<Engine>(texture, Vector2(-50, 0)));*/
	rocket->addPartManager(rktMan, Vector2(0, 0));
	//rocket->addPartManager(rktMan2, Vector2(0, 0));
	clock.restart();
}

void Player::update() {
	manageControls();
	rocket->update();
	clock.restart();
}

void Player::draw() {
	rocket->draw();
}

long double* Player::getThrottlePtr() {
	return &throttle;
}

long double* Player::getSteeringPtr() {
	return &steering;
}

void Player::manageControls() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		throttle += (long double)(clock.getElapsedTime().asSeconds()) * 1500;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		throttle -= (long double)(clock.getElapsedTime().asSeconds()) * 1500;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		steering = 0;
	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		steering = 100;
	} else {
		steering = 50; //50 is neutral; no steering; strait.
	}

	if (throttle > 100) {
		throttle = 100;
	} else if (throttle < 0) {
		throttle = 0;
	}

	if (steering > 100) {
		steering = 100;
	} else if (steering < 0) {
		steering = 0;
	}
	rocket->setThrottle(throttle);
	rocket->setSteering(steering);
}