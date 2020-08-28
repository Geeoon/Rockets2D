#include "UIElement.h"

UIElement::UIElement(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP) {
	texture = t;
	window = w;
	x = xP;
	y = yP;
}

void UIElement::update() {

}

void UIElement::synchronousUpdate() {

}