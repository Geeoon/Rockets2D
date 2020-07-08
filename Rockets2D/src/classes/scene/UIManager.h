#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "UIElementManager.h"

class UIManager
{
public:
	UIManager();
	void update();
	sf::RenderTexture* getGameTexture();
	bool isOpen();
private:
	sf::RenderWindow window; //for texture and ui elements to be rendered together
	sf::RenderTexture uiTexture; //for the UI itself
	sf::RenderTexture gameTexture; //for the scene itself only.
	sf::ContextSettings videoSettings;
	std::unique_ptr<UIElementManager> startMenu;
	sf::Font font;
	void updateUI();
	void pollEvent();
};

