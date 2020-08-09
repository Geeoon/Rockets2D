#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class UIElement
{
public:
	UIElement(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP);
	virtual void update();

protected:
	int x = 0;
	int y = 0;
	sf::RenderTexture* texture = nullptr;
	sf::RenderWindow* window = nullptr;
};

