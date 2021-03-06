#include "UIBackground.h"

UIBackground::UIBackground(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, int wi, int h) : UIElement(t, w, xP, yP) {
	width = wi;
	height = h;
	backgroundColor = sf::Color::Black;
	outlineColor = sf::Color(0, 255, 65);
	sprite.setFillColor(backgroundColor);
	sprite.setOutlineThickness(2);
	sprite.setOutlineColor(outlineColor);
	sprite.setSize(sf::Vector2f(width - sprite.getOutlineThickness() * 2, height - sprite.getOutlineThickness() * 2));
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	sprite.setPosition((float)x, (float)y);
}

void UIBackground::update() {
	texture->draw(sprite);
}

void UIBackground::setPos(int xP, int yP) {
	x = xP;
	y = yP;
	sprite.setPosition((float)x, (float)y);
}

void UIBackground::setCenter(int xP, int yP) {
	sprite.setOrigin((float)xP, (float)yP);
}