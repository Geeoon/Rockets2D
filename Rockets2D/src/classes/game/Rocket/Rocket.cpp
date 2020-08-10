#include "Rocket.h"

Rocket::Rocket(sf::RenderTexture* t, const Vector2& pos) : Object(pos, 0) {
	texture = t;
}

Rocket::Rocket(sf::RenderTexture* t, const Vector2& pos, long double ori) : Object(pos, 0) {
	texture = t;
	orientation = ori;
}

Rocket::Rocket(sf::RenderTexture* t, const Vector2& pos, long double ori, const Vector2& vel) : Object(pos, 0, vel) {
	texture = t;
	orientation = ori;
}

void Rocket::update() {
	mass = 0;
	for (std::shared_ptr<RocketPartsManager> partManager : partManagers) {
		partManager->setThrottle(throttle);
		partManager->setPosition(position);
		ForcePosition FP;
		FP = partManager->update();
		mass += partManager->getMass();
		centerOfMass += (partManager->getCenterOfMass() + partManager->getRelativePosition()) * partManager->getMass();
		applyForceRel(FP.force);
		applyTorque(FP.force.getMagnitude() * FP.position.getMagnitude() * sinl(FP.force.getAngle() - FP.position.getAngle()));
	}
	std::cout << throttle << std::endl;
	Object::update();
}

void Rocket::draw() {
	for (std::shared_ptr<RocketPartsManager> partManager : partManagers) {
		partManager->draw();
	}
}

void Rocket::addPartManager(std::shared_ptr<RocketPartsManager> pM, const Vector2& relPos) {
	partManagers.push_back(pM);
	partManagers.back()->setRelativePosition(relPos);
}

void Rocket::setThrottle(long double t) {
	throttle = t;
}