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
	Vector2 update();
	void draw();
	void addPart(std::shared_ptr<RocketPart> part);

private:
	std::vector<std::shared_ptr<RocketPart>> parts;
};

