#pragma once
#include <vector>
#include "UIString.h"
#include "UIElement.h"

class UIRadio : public UIString
{
public:
	UIRadio(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, std::string v, sf::Font* f, int s);
	void update() override;
	bool* getIsOnPtr();

private:
	bool isOn = false;
	sf::CircleShape outer;
	sf::CircleShape inner;
};

