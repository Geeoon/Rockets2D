#include "Button.h"

Button::Button(sf::RenderTexture* t, sf::RenderWindow* w, void(*m)()) {
	texture = t;
	window = w;
	method = m;
}

void Button::update() {
	if (button.getGlobalBounds().contains(texture->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
		method();
	}
}