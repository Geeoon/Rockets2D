#include "UIString.h"

UIString::UIString(std::string v, int xP, int yP, sf::RenderTexture* t, sf::Font* f, int s) {
	texture = t;
	value = v;
	x = xP;
	y = yP;
	font = f;
	size = s;
	reset();
}

void UIString::draw() {
	texture->draw(text);
}

void UIString::setVal(std::string v) {
	value = v;
}

void UIString::setPos(int xP, int yP) {
	x = xP;
	y = yP;
}

void UIString::setFont(sf::Font* f) {
	font = f; //calling this function could cause a memory leak in some cases.
}

void UIString::setSize(int s) {
	size = s;
}

void UIString::setColor(sf::Color c) {
	color = c;
}

void UIString::reset() {
	text.setFont(*font);
	text.setFillColor(sf::Color::White);
	text.setString(value);
	text.setCharacterSize(30);
	text.setPosition(x, y);
}