#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>
#include "../game/FreeBody.h"
#include "GameElements/FreeBodyDiagram.h"
#include "UIElements/UIBackground.h"
#include "UIElements/UIRadioList.h"
#include "UIElements/UIElement.h"
#include "UIElements/UIEmblem.h"
#include "UIElements/UIString.h"
#include "UIElements/UISlider.h"
#include "UIElements/Button.h"

class UIElementManager
{
public:
	UIElementManager(sf::RenderTexture* t, sf::RenderWindow* w, sf::Font* f, sf::Sound* ho, sf::Sound* cl, sf::Sound* uCl);
	void update();
	void synchronousUpdate();
	void setActive(bool a);
	void addUIString(std::string v, int xP, int yP, int s);
	void addUIString(std::string v, int xP, int yP, int s, UIString::UIString_alignment a);
	void addUIString(std::string v, int xP, int yP, int s, UIString::UIString_alignment a, UIString::UIString_alignment a2);
	void addButton(std::string v, int xP, int yP, int s, const std::function<void()>& m);
	void addBackground(int xP, int yP, int wid, int hei);
	void addSlider(int xP, int yP, int len, long double* oVal);
	void addFBD(int xP, int yP, int s, FreeBody* fb, bool* canD);
	void addRadioList(int xP, int yP, int s, std::string args[], size_t num);
	void addRadioList(int xP, int yP, int s, std::string args[], size_t num, int def);
	void addEmblem(sf::RenderTexture* t2, long double* xP, long double* yP, std::string titl, std::string d);
private:
	bool active = false;
	std::vector<std::shared_ptr<UIElement>> elements;
	sf::Font* font;
	sf::RenderTexture* texture;
	sf::RenderWindow* window;
	sf::Sound* click;
	sf::Sound* hover;
	sf::Sound* unClick;
};

