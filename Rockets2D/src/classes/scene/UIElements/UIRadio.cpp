#include "UIRadio.h"

UIRadio::UIRadio(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, std::string v, sf::Font* f, int s) : UIString(t, w, xP, yP, v, f, s) {
	inner.setFillColor(sf::Color(0, 255, 65));
	outer.setOutlineColor(sf::Color(0, 255, 65));
	outer.setOutlineThickness(2);
	outer.setFillColor(sf::Color::Transparent);
	inner.setRadius((float)s / 2);
	outer.setRadius(3 * (float)s / 8);
	outer.setPosition(xP, yP);
	inner.setPosition(xP, yP);
}

void UIRadio::update() {
	if (outer.getGlobalBounds().contains(texture->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { //click
			isOn = true;
		}
	}

	texture->draw(outer);

	if (isOn) {
		texture->draw(inner);
	}
}

bool* UIRadio::getIsOnPtr() {
	return &isOn;
}