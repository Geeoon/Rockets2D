#pragma once
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button(sf::RenderTexture* t, sf::RenderWindow* w, void(*m)());
	void update();
private:
	int textSize = 0;
	std::string text;
	sf::RectangleShape button;
	sf::RenderTexture* texture;
	sf::RenderWindow* window;
	void(*method)();
};

