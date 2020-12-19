#include "UIElement.h"

UIElement::UIElement(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP) {
	texture = t;
	window = w;
	x = xP;
	y = yP;
	if (!(t && w)) {
		throw std::invalid_argument{ "nullptr exception" };
	}
}

void UIElement::update() {

}

void UIElement::synchronousUpdate() {

}