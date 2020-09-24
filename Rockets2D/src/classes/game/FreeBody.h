#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Vector2.h"
#include <iostream>

class FreeBody
{
public:
	FreeBody();
	void addForce(Vector2 v);
	Vector2 getNet();
	std::vector<Vector2>& getForces();

private:
	std::vector<Vector2> forces;
	Vector2 netForce = Vector2(0, 0);
};

