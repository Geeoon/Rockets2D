#include "ObjectManager.h"

ObjectManager::ObjectManager(sf::RenderTexture* t) {
	texture = t;
}

void ObjectManager::update() {
	for (int i = 0; i < objects.size(); i++) {
		for (int j = i + 1; j < objects.size(); j++) {
			calcNApplyGravity(objects[i], objects[j]);
		}
	}

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

void ObjectManager::calcNApplyGravity(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2) {
	Vector2 resultantForce21 = Vector2::constructFromPolar(-G * ((obj1->getMass() * obj2->getMass()) / powl((obj2->getPosition() - obj1->getPosition()).getMagnitude(), 2)), (obj1->getPosition() - obj2->getPosition()).getAngle());
	obj1->applyForce(resultantForce21 * 1000000);
	obj2->applyForce(-resultantForce21);
	std::cout << resultantForce21.getMagnitude() << std::endl;
}