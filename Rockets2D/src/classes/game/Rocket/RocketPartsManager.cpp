#include "RocketPartsManager.h"

RocketPartsManager::RocketPartsManager() : ObjectBasic(Vector2(0, 0), 0) {
	//parts.resize(0);
}

void RocketPartsManager::update() {
	mass = 0;
	for (RocketPart part : parts) {
		part.update();
		mass += part.getMass();
	}
}

void RocketPartsManager::draw() {
	for (RocketPart part : parts) {
		part.draw();
	}
}

void RocketPartsManager::addPart(const RocketPart& part) {
	parts.push_back(part);
}