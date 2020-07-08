#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include "UIString.h"
#include "Button.h"

class UIElementManager
{
public:
	UIElementManager(sf::RenderTexture* t, sf::RenderWindow* w, sf::Font* f, sf::Sound* ho, sf::Sound* cl);
	void update();
	void setActive(bool a);
	void addUIString(std::string v, int xP, int yP, int s);
	void addUIString(std::string v, int xP, int yP, int s, UIString::UIString_alignment a);
	void addButton(std::string v, int xP, int yP, int s, void(*m)());
private:
	bool active = false;
	std::vector<Button> buttons;
	std::vector<UIString> strings;
	sf::Font* font;
	sf::RenderTexture* texture;
	sf::RenderWindow* window;
	sf::Sound* click;
	sf::Sound* hover;
};

