#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include "../game/FreeBody.h"
#include "GameElements/FreeBodyDiagram.h"
#include "UIElements/UIBackground.h"
#include "UIElements/UIElement.h"
#include "UIElements/UIString.h"
#include "UIElements/UISlider.h"
#include "UIElements/Button.h"

class UIElementManager
{
public:
	UIElementManager(sf::RenderTexture* t, sf::RenderWindow* w, sf::Font* f, sf::Sound* ho, sf::Sound* cl, sf::Sound* uCl);
	void update();
	void setActive(bool a);
	void addUIString(std::string v, int xP, int yP, int s);
	void addUIString(std::string v, int xP, int yP, int s, UIString::UIString_alignment a);
	void addUIString(std::string v, int xP, int yP, int s, UIString::UIString_alignment a, UIString::UIString_alignment a2);
	void addButton(std::string v, int xP, int yP, int s, const std::function<void()>& m);
	void addBackground(int xP, int yP, int wid, int hei);
	void addSlider(int xP, int yP, int len, long double* oVal);
	void addFBD(int xP, int yP, int s, FreeBody* fb);
private:
	bool active = false;
	std::vector<std::shared_ptr<UIElement>> elements;
	std::vector<Button> buttons;
	std::vector<UIString> strings;
	sf::Font* font;
	sf::RenderTexture* texture;
	sf::RenderWindow* window;
	sf::Sound* click;
	sf::Sound* hover;
	sf::Sound* unClick;
};

