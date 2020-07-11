#include "ObjectManager.h"

ObjectManager::ObjectManager(sf::RenderTexture* t) {
	texture = t;
}

void ObjectManager::update() {
	/*
	for (Object& obj1 : objects) {
		for (Object& obj2 : objects) {
			if (&obj1 != &obj2) {

			}
		}
	}
	*/

	for (Object& obj : objects) {
		obj.applyForce(Vector2(1, -1));
		obj.update();
	}
}

void ObjectManager::draw() {
	for (Object& obj : objects) {
		obj.draw();
	}
}

void ObjectManager::addObject(double xP, double yP, double m, double r) {
	objects.push_back(Object(texture, xP, yP, m, r));
}