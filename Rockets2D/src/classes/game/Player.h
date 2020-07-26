#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Player
{
public:
	Player(sf::RenderTexture* t);
	void update();
	void draw();
	std::shared_ptr<Object> getObj();
private:
	//for testing only, delete soon
	std::shared_ptr<Object> obj;
	Vector2 dimentions = Vector2(100, 100);
	sf::RectangleShape sprite;
	//Delete above to comment
	void manageControls();
	sf::RenderTexture* texture = nullptr;
	sf::RectangleShape playerRocket;
};