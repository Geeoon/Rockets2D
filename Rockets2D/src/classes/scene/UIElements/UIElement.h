#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define M_PI 3.14159265358979323851280895940618620443274267017841339111328125

class UIElement
{
public:
	UIElement(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP);
	virtual void update();
	virtual void synchronousUpdate();

protected:
	int x = 0;
	int y = 0;
	sf::RenderTexture* texture = nullptr;
	sf::RenderWindow* window = nullptr;
};

