#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Object.h"
#include "Force.h"

#define G 0.00000000006673L
class ObjectManager
{
public:
	ObjectManager(sf::RenderTexture* t);
	void update();
	void draw();
	void addObject(const Vector2& pos, double m);
	void addObject(const Vector2& pos, double m, const Vector2& vel);
	void addObject(std::shared_ptr<Object> obj);
	std::vector<std::shared_ptr<Object>>* getObjects();
private:
	void calcNApplyGravity(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2);
	void detectCollision(std::shared_ptr<Object> obj1, std::shared_ptr<Object> obj2);
	std::vector<std::shared_ptr<Object>> objects;
	sf::RenderTexture* texture;
};

