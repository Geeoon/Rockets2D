#pragma once
#include <vector>
#include "Object.h"

class ObjectManager
{
public:
	ObjectManager(sf::RenderTexture* t);
	void update();
	void addObject(Vector2 pos, double m);
	void addObject(Vector2 pos, double m, Vector2 vel);
	void addObject(std::shared_ptr<Object> obj);
private:
	std::vector<std::shared_ptr<Object>> objects;
	sf::RenderTexture* texture;
};

