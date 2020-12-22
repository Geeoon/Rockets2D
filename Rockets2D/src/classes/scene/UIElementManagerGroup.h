#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include "../game/FreeBody.h"
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
	void addBackground(int page, int xP, int yP, int wid, int hei);
	void addSlider(int page, int xP, int yP, int len, long double* oVal);
	void addFBD(int page, int xP, int yP, int s, FreeBody* fb, bool* canD, long double* o);
	void addRadioList(int page, int xP, int yP, int s, std::string args[], size_t num);
	void addRadioList(int page, int xP, int yP, int s, std::string args[], size_t num, int def);
	void addEmblem(int page, sf::RenderTexture* t2, long double* xP, long double* yP, std::string titl, std::string d, UIEmblem::type shape, long double* aPtr, long double r);
	void setActive(bool active);
	void update();
	void synchronousUpdate();
	void setActivePage(size_t page);
private:
	bool isActive = false;
	sf::RenderTexture* texture;
	sf::RenderWindow* window;
	sf::Font* font;
	sf::Sound* hover;
	sf::Sound* click;
	sf::Sound* unClick;
	std::vector<std::unique_ptr<UIElementManager>> pages;
};