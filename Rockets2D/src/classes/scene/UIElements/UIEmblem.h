#pragma once
#include "UIElement.h"
#include "UIString.h"
#include "UIBackground.h"
#include "Button.h"

class UIEmblem : public UIElement
{
public:
	UIEmblem(sf::RenderTexture* t, sf::RenderTexture* t2, sf::RenderWindow* w, long double* xP, long double* yP, std::string titl, std::string d, sf::Font* f);
	void update() override;
private:
	long double* xPointer = nullptr;
	long double* yPointer = nullptr;
	sf::CircleShape sprite;
	std::unique_ptr<UIBackground> background;
	sf::RenderTexture* texture2 = nullptr;
	std::unique_ptr<UIString> title;
	std::unique_ptr<UIString> description;
	std::unique_ptr<Button> focus;
	std::unique_ptr<Button> unFocus;
};