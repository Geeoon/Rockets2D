#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectManager.h"

class Game
{
public:
	Game(sf::RenderTexture* t);
	void start();
	void stop();
	void quit();
	void update();
	void setPause(bool p);
	void draw();
private:
	bool hasStarted = false;
	bool isPaused = false;
	bool isQuit = false;
	sf::RenderTexture* texture = nullptr;
	sf::RenderTexture* fbTexture = nullptr;
	std::unique_ptr<ObjectManager> objMan;
};

