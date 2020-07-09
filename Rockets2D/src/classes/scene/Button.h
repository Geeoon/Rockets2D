#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <functional>

class Button
{
public:
	Button(sf::RenderTexture* t, sf::RenderWindow* w, const std::function<void()>& m, int s, std::string v, sf::Font* f, int xP, int yP, sf::Sound* ho, sf::Sound* cl);
	void update();
private:
	bool hasChanged = true; //this bool tells whether the color has changed; it is used to functions aren't ran when they dont' need to be.
	int textSize = 0;
	int buttonPadding = 0;
	int x = 0;
	int y = 0;
	std::function<void()>(onClick);
	void reset();
	std::string value;
	sf::RectangleShape button;
	sf::RenderTexture* texture;
	sf::RenderWindow* window;
	sf::Color borderColor;
	sf::Color backgroundColor;
	sf::Color textColor;
	sf::Font* font;
	sf::Text text;
	sf::Sound* hover;
	sf::Sound* click;
};

