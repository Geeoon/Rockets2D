#include "Scene.h"

Scene::Scene() {
	game = std::make_shared<Game>(ui.getGameTexture());
	ui.setGame(game);
}

void Scene::start() {
	while (ui.isOpen()) {
		std::thread gameThread(&Game::update, game.get());
		gameThread.detach();
		ui.update();
	}
}