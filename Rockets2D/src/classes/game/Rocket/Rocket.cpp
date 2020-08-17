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
	momentOfInertia = 0;
	ForcePosition FP;
	for (std::shared_ptr<RocketPartsManager> partManager : partManagers) {
		partManager->setThrottle(throttle);
		partManager->setSteering(steering);
		partManager->setPosition(position);
		partManager->setOrientation(orientation);
		FP += partManager->update();
		mass += partManager->getMass();
		centerOfMass += (partManager->getCenterOfMass() + partManager->getRelativePosition()) * partManager->getMass();

		momentOfInertia += partManager->getMass() * powl((partManager->getCenterOfMass() + partManager->getRelativePosition()).getMagnitude(), 2);
	}
	centerOfMass = centerOfMass / mass;
	applyForce(FP.force);
	if (FP.force.getMagnitude() > 0) {
		//applyTorque(FP.force.getMagnitude() * (FP.position - centerOfMass).getMagnitude() * sinl(((FP.position - centerOfMass).getAngle() - orientation) - FP.force.getAngle()));
	}
	std::cout << centerOfMass.getX() << " " << centerOfMass.getY() << std::endl;

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

void Rocket::setSteering(long double s) {
	steering = s - 50;
}