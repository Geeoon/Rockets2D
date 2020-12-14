#include "Game.h"

Game::Game(sf::RenderTexture* t) {
	texture = t;
	objMan = std::make_unique<ObjectManager>(t);
	objMan->addObject(std::make_unique<SpaceObject>("Moon", "Earth's best friend.", texture, Vector2(385000.6 * powl(10, 3), 0), 7.346L * powl(10, 22), 1.7371L * powl(10, 6), Vector2(0, 1017.47))); //moon
	objMan->addObject(std::make_unique<SpaceObject>("Earth", "Home", texture, Vector2(0, 0), 5.972L * powl(10, 24), 6.371L * powl(10, 6))); //earth
	player = std::make_unique<Player>(t);
	player->setSyncUpdates(&syncFuncs);
	player->getRocketPtr()->setPosition(Vector2(6.371L * powl(10, 6), 0));
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
		player->update((isPaused && hasStarted));
		if (hasStarted && !isPaused) {
			objMan->update();
		}
	}
}

void Game::setPause(bool p) {
	isPaused = p;
}

bool Game::getIsPaused() {
	return isPaused;
}

void Game::draw() { //this is called from another thread; don't rely on it for synchronous actions.
	if (hasStarted) {
		texture->clear(sf::Color::Transparent);
		objMan->draw();
		texture->display();
	} else {
		texture->clear();
		texture->display();
	}
}

void Game::draw(const Vector2& pos, long double ori) { //this is called from another thread; don't rely on it for synchronous actions.
	if (hasStarted) {
		texture->clear(sf::Color::Transparent);
		objMan->draw(pos, ori);
		//player->getRocketPtr()->draw(pos, ori);
		texture->display();
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

ObjectManager* Game::getObjMan() {
	return objMan.get();
}