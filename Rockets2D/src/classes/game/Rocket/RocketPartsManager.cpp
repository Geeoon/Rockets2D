#include "RocketPartsManager.h"

RocketPartsManager::RocketPartsManager() : ObjectBasic(Vector2(0, 0), 0) {
	//parts.resize(0);
}

void RocketPartsManager::update() {
	mass = 0;
	centerOfMass = Vector2(0, 0);
	/*
	long double COMx = 0;
	long double COMy = 0;
	*/
	for (std::shared_ptr<RocketPart> part : parts) {
		part->setPosition(position);
		part->setOrientation(orientation);
		part->update();
		mass += part->getMass();
		/*
		COMx += part->getMass() * (part->getCenterOfMass().getX() + part->getPosition().getX());
		COMy += part->getMass() * (part->getCenterOfMass().getY() + part->getPosition().getY());
		*/
		centerOfMass += (part->getCenterOfMass() + part->getRelativePosition()) * part->getMass();
	}
	centerOfMass = centerOfMass / mass;
	std::cout << "Center of Mass: " << centerOfMass.getX() << ", " << centerOfMass.getY() << std::endl;
}

void RocketPartsManager::draw() {
	for (std::shared_ptr<RocketPart> part : parts) {
		part->draw();
	}
}

void RocketPartsManager::addPart(std::shared_ptr<RocketPart> part) {
	parts.push_back(part);
}