#include "Game.h"

Game::Game(sf::RenderTexture* t) {
	texture = t;
	objMan = std::make_unique<ObjectManager>(t);
	objMan->addObject(0, 0, 5.973 * pow(10, 24), 6.371 * pow(10, 7));
}

void Game::start() {
	hasStarted = true;
	isPaused = false;
}

void Game::stop() {
	hasStarted = false;
}

void Game::quit() {
	isQuit = true;
}

void Game::update() {
	while (!isQuit) {
		if (hasStarted && !isPaused) {
			objMan->update();
		}
	}
}

void Game::setPause(bool p) {
	isPaused = p;
}

void Game::draw() {
	if (hasStarted) {
		if (!isPaused) {
			texture->clear(sf::Color::Transparent);
			objMan->draw();
			texture->display();
		}
	} else {
		texture->clear();
		texture->display();
	}
}