#include "Game.h"

Game::Game(sf::RenderTexture* t) {
	texture = t;
	objMan = std::make_unique<ObjectManager>(t);
	//testObject = std::make_unique<SpaceObject>(texture, Vector2(0, 0), 5.973L * pow(10, 24), 6.371L * pow(10, 7));
	//testObject2 = std::make_unique<SpaceObject>(texture, Vector2(5.971L * pow(10, 7) + 3.82L * pow(10, 8), 0), 7.64767309L * pow(10, 22), 1.7371 * pow(10, 7), Vector2(0, 950.0150896));
	//objMan->addObject(testObject->getObject());
	//objMan->addObject(testObject2->getObject());
	player = std::make_unique<Player>(t);
	player->setSyncUpdates(&syncFuncs);
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
		if (hasStarted) {
			player->update(isPaused);
		}
		if (hasStarted && !isPaused) {
			objMan->update();
			//testObject->update();
			//testObject2->update();
		}
	}
}

void Game::setPause(bool p) {
	isPaused = p;
}

void Game::draw() { //this is called from another thread; don't rely on it for synchronous actions.
	if (hasStarted) {
		if (!isPaused) {
			texture->clear(sf::Color::Transparent);
			//testObject->draw();
			//testObject2->draw();
			player->draw();
			texture->display();
		}
	} else {
		texture->clear();
		texture->display();
	}
}

void Game::addToSync(const std::function<void()>& f) {
	syncFuncs.push_back(f);
}

Player* Game::getPlayer() {
	return player.get();
}

void Game::syncronousUpdate() {
	for (const std::function<void()>& f : syncFuncs) {
		f();
	}
}