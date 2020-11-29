#include "Player.h"

Player::Player(sf::RenderTexture* t) {
	texture = t;
	rocket = std::make_shared<Rocket>("You", "Yourself.", texture, Vector2(0, 0));
	std::shared_ptr<RocketPartsManager>rktMan = std::make_shared<RocketPartsManager>();
	rktMan->addPart(std::make_shared<Engine>(texture, Vector2(0, 0)));
	rktMan->addPart(std::make_shared<FuelTank>(texture, Vector2(0, -3.2)));
	rocket->addPartManager(rktMan, Vector2(0, 0));
	clock.restart();
}

void Player::update(bool p) {
	gamePause = p;
	if (!p) {
		rocket->update();
		for (std::function<void()>& sf : *syncUpdateVect) {
			sf();
		}
		rocket->Object::update();

	} else {
		rocket->resetTime();
	}
	
}

void Player::draw() {
	rocket->draw();
}

void Player::setSyncUpdates(std::vector<std::function<void()>>* fv) {
	syncUpdateVect = fv;
}

long double* Player::getThrottlePtr() {
	return &throttle;
}

long double* Player::getSteeringPtr() {
	return &steering;
}

std::shared_ptr<Rocket> Player::getRocketPtr() {
	return rocket;
}

void Player::manageControls() { //gets called in the UIManager class.
	elapsedTime = clock.getElapsedTime();
	clock.restart();
	if (!gamePause) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			throttle += (long double)(elapsedTime.asSeconds()) * 100;

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			throttle -= (long double)(elapsedTime.asSeconds()) * 100;
		}
		if (throttle > 100) {
			throttle = 100;
		} else if (throttle < 0) {
			throttle = 0;
		}
		rocket->setThrottle(throttle);
	}
}

void Player::manageEvents(sf::Event e) { //gets called in the UIManager class.
	if (!gamePause) {
		switch (e.type) {
		case sf::Event::KeyPressed:
			switch (e.key.code) {
			case sf::Keyboard::A:
				steering = 0;
				break;
			case sf::Keyboard::D:
				steering = 100;
				break;
			case sf::Keyboard::LShift:
				steering = 50;
				break;
			}
			break;

		case sf::Event::KeyReleased:
			switch (e.key.code) {
			case sf::Keyboard::A:
				steering = 50;
				break;
			case sf::Keyboard::D:
				steering = 50;
				break;
			}
			break;
		}

		if (steering > 100) {
			steering = 100;
		} else if (steering < 0) {
			steering = 0;
		}

		rocket->setSteering(steering);
	}
}