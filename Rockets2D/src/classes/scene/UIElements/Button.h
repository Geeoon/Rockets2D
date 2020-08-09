#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <functional>
#include "UIElement.h"

class Button : public UIElement
{
public:
	Button(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, const std::function<void()>& m, int s, std::string v, sf::Font* f, sf::Sound* ho, sf::Sound* cl, sf::Sound* uCl);
	void update() override;

private:
	bool hasChanged = true; //this bool tells whether the color has changed; it is used to functions aren't ran when they dont' need to be.
	bool beingPressed = false;
	int textSize = 0;
	int buttonPadding = 0;
	std::function<void()>(onClick);
	void reset();
	std::string value;
	sf::RectangleShape button;
	sf::Color borderColor;
	sf::Color backgroundColor;
	sf::Color textColor;
	sf::Font* font;
	sf::Text text;
	sf::Sound* hover;
	sf::Sound* click;
	sf::Sound* unClick;
};

