#include "RocketPartsManager.h"

RocketPartsManager::RocketPartsManager() : ObjectBasic(Vector2(0, 0), 0) {
	//parts.resize(0);
}

void RocketPartsManager::update() {
	mass = 0;
	centerOfMass = Vector2(0, 0);
	for (std::shared_ptr<RocketPart> part : parts) {
		part->setPosition(position);
		part->setOrientation(orientation);
		part->update();
		mass += part->getMass();
		centerOfMass += (part->getCenterOfMass() + part->getPosition()) * part->getMass();//this shit wont work D:<  I need to think of some way to get a center of mass vector and a mass.
	}
}

void RocketPartsManager::draw() {
	for (std::shared_ptr<RocketPart> part : parts) {
		part->draw();
	}
}

void RocketPartsManager::addPart(std::shared_ptr<RocketPart> part) {
	parts.push_back(part);
}