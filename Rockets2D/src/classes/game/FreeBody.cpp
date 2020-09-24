#include "FreeBody.h"

FreeBody::FreeBody() {

}

void FreeBody::addForce(Vector2 v) {
	forces.push_back(v);
	std::cout << v.getIsPush();
	netForce += v;
}

Vector2 FreeBody::getNet() {
	return netForce;
}

std::vector<Vector2>& FreeBody::getForces() {
	return forces;
}