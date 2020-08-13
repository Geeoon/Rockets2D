#pragma once
#include "Vector2.h"

struct ForcePosition {
	Vector2 force = Vector2(0, 0);
	Vector2 position = Vector2(0, 0);
	ForcePosition operator+=(const ForcePosition& fp) {
		force += fp.force;
		position = position * force.getMagnitude();
		position += fp.position * fp.force.getMagnitude();
		position = position / force.getMagnitude();
		return *this;
	}
};