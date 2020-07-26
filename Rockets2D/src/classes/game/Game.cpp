#include "Game.h"

Game::Game(sf::RenderTexture* t) {
	texture = t;
	objMan = std::make_unique<ObjectManager>(t);
	testObject = std::make_unique<SpaceObject>(texture, Vector2(0, 0), 5.973L * pow(10, 24), 6.371L * pow(10, 7));
	testObject2 = std::make_unique<SpaceObject>(texture, Vector2(5.971L * pow(10, 7) + 3.82L * pow(10, 8), 0), 7.64767309L * pow(10, 22), 1.7371 * pow(10, 7), Vector2(0, 950.0150896));
	testEngine = std::make_unique<Engine>(texture, Vector2(0, 0), 10);
	objMan->addObject(testObject->getObject());
	objMan->addObject(testObject2->getObject());
	player = std::make_unique<Player>(t);
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
			player->update();
			objMan->update();
			testObject->update();
			testObject2->update();
			std::cout << testEngine->update().getY() << std::endl;
		}
	}
}

void Game::setPause(bool p) {
	isPaused = p;
}

void Game::draw() { //this is called from another thread; don't rely on it for syncronous actions.
	if (hasStarted) {
		if (!isPaused) {
			texture->clear(sf::Color::Transparent);
			testObject->draw();
			testObject2->draw();
			player->draw();
			testEngine->draw();
			texture->display();
		}
	} else {
		texture->clear();
		texture->display();
	}
}