#include "RocketPartsManager.h"

RocketPartsManager::RocketPartsManager() : ObjectBasic(Vector2(0, 0), 0) {
	//parts.resize(0);
}

Vector2 RocketPartsManager::update() {
	mass = 0;
	centerOfMass = Vector2(0, 0);
	Vector2 netForce = Vector2(0, 0);
	for (std::shared_ptr<RocketPart> part : parts) {
		part->setPosition(position);
		part->setOrientation(orientation);
		netForce += part->update();
		mass += part->getMass();
		centerOfMass += (part->getCenterOfMass() + part->getRelativePosition()) * part->getMass();
	}
	centerOfMass = centerOfMass / mass;
	return netForce;
}

void RocketPartsManager::draw() {
	orientation += 0.01;
	for (std::shared_ptr<RocketPart> part : parts) {
		part->draw();
	}
}

void RocketPartsManager::addPart(std::shared_ptr<RocketPart> part) {
	parts.push_back(part);
}