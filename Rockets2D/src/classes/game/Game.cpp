#include "Game.h"

Game::Game(sf::RenderTexture* t) {
	texture = t;
	objMan = std::make_unique<ObjectManager>(t);
	objMan->addObject(std::make_unique<SpaceObject>(texture, Vector2(1738.1L * 1000L, 0), 7.346L * powl(10, 22), 1738.1L * 1000L));
	player = std::make_unique<Player>(t);
	player->setSyncUpdates(&syncFuncs);
	objMan->addObject(player->getRocketPtr());
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
			objMan->draw();
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