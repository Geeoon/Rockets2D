#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class Player
{
public:
	Player(sf::RenderTexture* t);
	void update();
	void draw();
private:
	void manageControls();
	sf::RenderTexture* texture = nullptr;
};