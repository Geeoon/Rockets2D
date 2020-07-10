#pragma once
#include <vector>
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager();
	void update();
	void addObject();
private:
	std::vector<Object> objects;
	sf::RenderTexture* texture;

};

