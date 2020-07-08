#include "Scene.h"
Scene::Scene() {

}

void Scene::start() {
	while (ui.isOpen()) {
		ui.update();
	}
}