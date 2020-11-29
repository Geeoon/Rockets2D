#pragma once
#include <SFML/Graphics.hpp>
#include "UIElement.h"

class UIBackground : public UIElement
{
public:
	UIBackground(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, int wi, int h);
	void update() override;
	void setPos(int xP, int yP);
	void setCenter(int xP, int yP);

private:
	int width = 0;
	int height = 0;
	sf::RectangleShape sprite;
	sf::Color outlineColor;
	sf::Color backgroundColor;
};

