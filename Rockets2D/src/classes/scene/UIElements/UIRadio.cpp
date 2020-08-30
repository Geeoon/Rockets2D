#include "UIRadio.h"

UIRadio::UIRadio(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, std::string v, sf::Font* f, int s) : UIString(t, w, xP, yP, v, f, s) {
	inner.setFillColor(sf::Color(0, 255, 65));
	outer.setOutlineColor(sf::Color(0, 255, 65));
	outer.setOutlineThickness(2);
	outer.setFillColor(sf::Color::Transparent);
	outer.setRadius((float)s / 2);
	inner.setRadius(3 * (float)s / 8);
	outer.setOrigin(outer.getRadius(), outer.getRadius());
	inner.setOrigin(inner.getRadius(), inner.getRadius());
	outer.setPosition((float)xP, (float)yP + outer.getRadius());
	inner.setPosition((float)xP, (float)yP + outer.getRadius());
	text.setFillColor(sf::Color(0, 255, 65));
	text.setFont(*f);
	text.setPosition((float)xP + (float)s, (float)yP);
	text.setCharacterSize(s);
	text.setString(v);
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
	texture->draw(text);
}

bool* UIRadio::getIsOnPtr() {
	return &isOn;
}