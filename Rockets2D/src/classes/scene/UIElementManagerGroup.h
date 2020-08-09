#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "UIElementManager.h"
#include "UIElements/Button.h"
#include "UIElements/UIString.h"

class UIElementManagerGroup
{
public:
	UIElementManagerGroup(sf::RenderTexture* t, sf::RenderWindow* w, sf::Font* f, sf::Sound* ho, sf::Sound* cl, sf::Sound* uCl);
	void addPage();
	void addButton(int page, std::string v, int xP, int yP, int s, const std::function<void()>& m);
	void addUIString(int page, std::string v, int xP, int yP, int s);
	void addUIString(int page, std::string v, int xP, int yP, int s, UIString::UIString_alignment a);
	void addUIString(int page, std::string v, int xP, int yP, int s, UIString::UIString_alignment a, UIString::UIString_alignment a2);
	void setActive(bool active);
	void update();
	void setActivePage(int page);
private:
	bool isActive = false;
	sf::RenderTexture* texture;
	sf::RenderWindow* window;
	sf::Font* font;
	sf::Sound* hover;
	sf::Sound* click;
	sf::Sound* unClick;
	std::vector<UIElementManager> pages;
};