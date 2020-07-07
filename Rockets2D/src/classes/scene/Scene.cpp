#include "Scene.h"
Scene::Scene() {

}

void Scene::start() {
	while (!isQuit) {
		ui.update();
	}
}