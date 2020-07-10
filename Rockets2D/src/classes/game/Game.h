#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectManager.h"

class Game
{
public:
	Game(sf::RenderTexture* t);
	void start();
	void stop();
	void update();
	void setPause(bool p);
	void draw();
private:
	bool hasStarted = false;
	bool isPaused = false;
	sf::RenderTexture* texture;
	std::unique_ptr<ObjectManager> objMan;
};

