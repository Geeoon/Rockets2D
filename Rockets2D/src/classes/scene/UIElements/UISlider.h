#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "UIElement.h"

class UISlider : public UIElement
{
public:
	UISlider(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, int len, long double* oVal, sf::Sound* cl, sf::Sound* uCl);
	void update() override;
private:
	bool beingSlid = false;
	long double* outputValue = nullptr;
	int sliderLength = 0;
	sf::Color accentColor = sf::Color(0, 255, 65);
	sf::Color fillColor = sf::Color::Black;
	sf::RectangleShape slider;
	sf::RectangleShape bar;
	sf::Sound* click;
	sf::Sound* unClick;
};

