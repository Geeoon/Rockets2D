#pragma once
#include <vector>
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager(sf::RenderTexture* t);
	void update();
	void draw();
	void addObject(double xP, double yP, double m, double r);
private:
	std::vector<Object> objects;
	sf::RenderTexture* texture;
};

