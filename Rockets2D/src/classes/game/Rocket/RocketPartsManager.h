#pragma once
#include <iostream>
#include <vector>
#include "../ForcePosition.h"
#include "../Vector2.h"
#include "../ObjectBasic.h"
#include "RocketParts/RocketPart.h"

class RocketPartsManager : public ObjectBasic
{
public:
	RocketPartsManager();
	ForcePosition update();
	void setRelativePosition(const Vector2& relPos);
	Vector2 getRelativePosition();
	void draw();
	void drawAtPNR(const Vector2& p, long double r);
	void addPart(std::shared_ptr<RocketPart> part);
	void setThrottle(long double t);
	void setSteering(long double s);

private:
	long double throttle = 0;
	long double steering = 0;
	std::vector<std::shared_ptr<RocketPart>> parts;
	Vector2 relativePosition = Vector2(0, 0);
};

