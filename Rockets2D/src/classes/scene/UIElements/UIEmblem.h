#pragma once
#include "UIElement.h";
#include "UIString.h";
#include "UIBackground.h"
#include "Button.h"
class UIEmblem : public UIElement
{
public:
	UIEmblem(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, std::string titl, std::string d, sf::Font* f);
	void update() override;
private:
	sf::CircleShape sprite;
	std::unique_ptr<UIString> title;
	std::unique_ptr<UIString> description;
	std::unique_ptr<Button> focus;
	std::unique_ptr<Button> unFocus;
};

