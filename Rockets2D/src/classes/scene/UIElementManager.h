#pragma once
#include <vector>
#include "UIString.h"
#include "Button.h"

class UIElementManager
{
public:
	UIElementManager(sf::RenderTexture* t, sf::RenderWindow* w, sf::Font& f);
	void update();
	void setActive(bool a);
	void addUIString(std::string v, int xP, int yP, int s);
	void addButton();
private:
	bool active = false;
	std::vector<Button> buttons;
	std::vector<UIString> strings;
	sf::Font font;
	sf::RenderTexture* texture;
	sf::RenderWindow* window;
};

