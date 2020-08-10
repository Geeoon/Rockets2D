#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "UIElement.h"

class UIString : public UIElement
{
public:
	enum class UIString_alignment {left, center, right, top, bottom, middle};
	UIString(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, std::string v, sf::Font* f, int s);
	UIString(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, std::string v, sf::Font* f, int s, UIString_alignment a);
	UIString(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, std::string v, sf::Font* f, int s, UIString_alignment a, UIString_alignment a2);
	void update() override;
	void setVal(std::string v);
	void setPos(int xP, int yP);
	void setFont(sf::Font* f);
	void setSize(int s);
	void setColor(sf::Color c);
	void reset();
	void setAlignment(UIString_alignment a);

private:
	int size;
	std::string value;
	sf::Font* font;
	sf::Color color;
	sf::Text text;
};

