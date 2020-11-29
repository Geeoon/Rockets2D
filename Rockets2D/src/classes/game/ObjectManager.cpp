#include "ObjectManager.h"

ObjectManager::ObjectManager(sf::RenderTexture* t) {
	texture = t;
}

void ObjectManager::update() {
	for (size_t i = 0; i < objects.size(); i++) {
		for (size_t j = i + 1; j < objects.size(); j++) {
			calcNApplyGravity(objects[i], objects[j]);
			detectCollision(objects[i], objects[j]);
		}
	}

	//updating
	for (std::shared_ptr<Object> obj : objects) {
		obj->update();
	}
}

void ObjectManager::draw() {
	for (std::shared_ptr<Object> obj : objects) {
		obj->draw();
	}
}

void ObjectManager::addObject(std::string ti, std::string d, const Vector2& pos, double m) {
	objects.push_back(std::make_shared<Object>(ti, d, pos, m));
}

void ObjectManager::addObject(std::string ti, std::string d, const Vector2& pos, double m, const Vector2& vel) {
	objects.push_back(std::make_shared<Object>(ti, d, pos, m, vel));
}

void ObjectManager::addObject(std::shared_ptr<Object> obj) {
	objects.push_back(obj);
}

std::vector<std::shared_ptr<Object>>* ObjectManager::getObjects() {
	return &objects;
}

void ObjectManager::calcNApplyGravity(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2) {
	Vector2 resultantForce21 = Vector2::constructFromPolar(-G * ((obj1->getMass() * obj2->getMass()) / powl((obj2->getPosition() - obj1->getPosition()).getMagnitude(), 2)), (obj1->getPosition() - obj2->getPosition()).getAngle());
	obj1->applyForce(resultantForce21);
	obj2->applyForce(-resultantForce21);
}

void ObjectManager::detectCollision(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2) {
	
}