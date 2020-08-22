#pragma once
#include "Vector2.h"

struct ForcePosition {
	Vector2 force = Vector2(0, 0);
	Vector2 position = Vector2(0, 0);
	ForcePosition operator+=(const ForcePosition& fp) {
		position = position * force.getMagnitude();
		force += fp.force;
		position += fp.position * fp.force.getMagnitude();
		if (force.getMagnitude() != 0) {
			position = position / force.getMagnitude();
		} else {
			position = Vector2(0, 0);
		}
		return *this;
	}
};