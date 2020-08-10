#include "UIString.h"
#include <iostream>

UIString::UIString(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, std::string v, sf::Font* f, int s) : UIElement(t, w, xP, yP) {
	value = v;
	font = f;
	size = s;
	color = sf::Color(0, 255, 65);
	reset();
}

UIString::UIString(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, std::string v, sf::Font* f, int s, UIString_alignment a) : UIElement(t, w, xP, yP) {
	value = v;
	font = f;
	size = s;
	color = sf::Color(0, 255, 65);
	reset();
	setAlignment(a);
}

UIString::UIString(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, std::string v, sf::Font* f, int s, UIString_alignment a, UIString_alignment a2) : UIElement(t, w, xP, yP) {
	value = v;
	font = f;
	size = s;
	color = sf::Color(0, 255, 65);
	reset();
	setAlignment(a);
	setAlignment(a2);
}

void UIString::update() {
	texture->draw(text);
}

void UIString::setVal(std::string v) {
	value = v;
	reset();
}

void UIString::setPos(int xP, int yP) {
	x = xP;
	y = yP;
	reset();
}

void UIString::setFont(sf::Font* f) {
	font = f; //calling this function could cause a memory leak in some cases.
	reset();
}

void UIString::setSize(int s) {
	size = s;
	reset();
}

void UIString::setColor(sf::Color c) {
	color = c;
	reset();
}

void UIString::reset() {
	text.setFont(*font);
	text.setFillColor(color);
	text.setString(value);
	text.setCharacterSize(size);
	text.setPosition(x, y);
}

void UIString::setAlignment(UIString_alignment a) {
	switch (a) {
	case UIString_alignment::left:
		text.setOrigin(0, text.getOrigin().y);
		break;

	case UIString_alignment::center:
		text.setOrigin(text.getLocalBounds().width / 2, text.getOrigin().y);
		break;

	case UIString_alignment::right:
		text.setOrigin(text.getLocalBounds().width, text.getOrigin().y);
		break;

	case UIString_alignment::top:
		text.setOrigin(text.getOrigin().x, 0);
		break;

	case UIString_alignment::bottom:
		text.setOrigin(text.getOrigin().x, font->getLineSpacing(size));
		break;

	case UIString_alignment::middle:
		text.setOrigin(text.getOrigin().x, font->getLineSpacing(size) / 2);
	default:
		break;
	}
}