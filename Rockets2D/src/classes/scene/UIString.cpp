#include "UIString.h"

UIString::UIString(std::string v, int xP, int yP, sf::RenderTexture* t, sf::Font& f, int s) {
	texture = t;
	value = v;
	x = xP;
	y = yP;
	font = f;
	size = s;
}

void UIString::update() {
	sf::Text text(value, font, size);
	text.setFillColor(sf::Color::White);
	texture->draw(text);
}

void UIString::setVal(std::string v) {
	value = v;
}

void UIString::setPos(int xP, int yP) {
	x = xP;
	y = yP;
}

void UIString::setFont(sf::Font& f) {
	font = f;
}

void UIString::setSize(int s) {
	size = s;
}

void UIString::setColor(sf::Color c) {
	color = c;
}