#include "UIString.h"

UIString::UIString(std::string v, int xP, int yP, sf::RenderTexture* t, sf::Font* f, int s) {
	texture = t;
	value = v;
	x = xP;
	y = yP;
	font = f;
	size = s;
	color = sf::Color(0, 255, 65);
	reset();
}

void UIString::draw() {
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

	default:
		break;
	}
}