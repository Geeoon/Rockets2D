#pragma once
#include <iostream>
#include <vector>
#include "../Vector2.h"
#include "../ObjectBasic.h"
#include "RocketParts/RocketPart.h"

class RocketPartsManager : public ObjectBasic
{
public:
	RocketPartsManager();
	void update();
	void draw();
	void addPart(const RocketPart& part);

private:
	std::vector<RocketPart> parts;
};

