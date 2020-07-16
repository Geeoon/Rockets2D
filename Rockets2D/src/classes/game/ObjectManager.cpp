#include "ObjectManager.h"

ObjectManager::ObjectManager(sf::RenderTexture* t) {
	texture = t;
}

void ObjectManager::update() {
	/* applying forces
	for (Object& obj1 : objects) {
		for (Object& obj2 : objects) {
			if (&obj1 != &obj2) {

			}
		}
	}
	*/

	//updating
	for (std::shared_ptr<Object> obj : objects) {
		obj->update();
	}
}

void ObjectManager::addObject(Vector2 pos, double m) {
	objects.push_back(std::make_shared<Object>(pos, m));
}

void ObjectManager::addObject(Vector2 pos, double m, Vector2 vel) {
	objects.push_back(std::make_shared<Object>(pos, m, vel));
}

void ObjectManager::addObject(std::shared_ptr<Object> obj) {
	objects.push_back(obj);
}