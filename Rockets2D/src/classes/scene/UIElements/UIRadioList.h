#pragma once
#include "UIElement.h"
#include "UIRadio.h"

class UIRadioList : public UIElement
{
public:
	enum class type { horizontal, vertical };
	UIRadioList(type typ, sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, sf::Font* f, int s, std::string args[], size_t num);
	UIRadioList(type typ, sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, sf::Font* f, int s, std::string args[], size_t num, int def);
	void update() override;
	void addRadio(std::string v);
	std::vector<bool*> getBoolPtrArr();

private:
	sf::Font* font = nullptr;
	int textSize = 0;
	bool* currentOn = nullptr;
	std::vector<UIRadio> radios;
};