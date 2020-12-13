#include "RocketPartsManager.h"

RocketPartsManager::RocketPartsManager() : ObjectBasic(Vector2(0, 0), 0) {
	//parts.resize(0);
}

ForcePosition RocketPartsManager::update() {
	mass = 0;
	centerOfMass = Vector2(0, 0);
	ForcePosition netForcePosition;
	for (std::shared_ptr<RocketPart> part : parts) {
		part->setThrottle(throttle);
		part->setSteering(steering);
		part->setPosition(position);
		part->setOrientation(orientation);
		Vector2 force = part->update();
		netForcePosition.force += force;
		netForcePosition.position += (part->getCenterOfMass() + part->getRelativePosition()) * force.getMagnitude();
		mass += part->getMass();

		centerOfMass += (part->getCenterOfMass() + part->getRelativePosition()) * part->getMass();
	}
	centerOfMass = centerOfMass / mass;

	if (netForcePosition.force.getMagnitude() > 0) {
		netForcePosition.position = netForcePosition.position / netForcePosition.force.getMagnitude();
		
	} else {
		netForcePosition.position = Vector2(0, 0);
	}
	return netForcePosition;
}

void RocketPartsManager::setRelativePosition(const Vector2& relPos) {
	relativePosition = relPos;
}

Vector2 RocketPartsManager::getRelativePosition() {
	return relativePosition;
}

void RocketPartsManager::draw() {
	for (std::shared_ptr<RocketPart> part : parts) {
		part->draw();
	}
}

void RocketPartsManager::draw(const Vector2& p, long double r) {
	for (std::shared_ptr<RocketPart> part : parts) {
		part->draw(p, r);
	}
}

void RocketPartsManager::addPart(std::shared_ptr<RocketPart> part) {
	parts.push_back(part);

}

void RocketPartsManager::setThrottle(long double t) {
	throttle = t;
}

void RocketPartsManager::setSteering(long double s) {
	steering = s;
}