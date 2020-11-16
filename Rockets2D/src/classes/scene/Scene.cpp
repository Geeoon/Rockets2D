#include "Scene.h"

Scene::Scene() {
	game = std::make_shared<Game>(ui.getGameTexture());
	ui.setGame(game);
	game->addToSync(ui.getSyncFuncs());
}

Scene::~Scene() {

}

void Scene::start() {
	std::thread gameThread(&Game::update, game.get());
	gameThread.detach();
	while (ui.isOpen()) {
		ui.update();
	}
}