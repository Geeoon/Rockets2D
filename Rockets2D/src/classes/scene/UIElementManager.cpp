#include "UIElementManager.h"

UIElementManager::UIElementManager(sf::RenderTexture* t, sf::RenderWindow* w, sf::Font* f) {
	texture = t;
	window = w;
	font = f;
}

void UIElementManager::update() {
	if (active) {
		for (UIString& string : strings) {
			string.draw();
		}
	}
}

void UIElementManager::setActive(bool a) {
	active = a;
}

void UIElementManager::addUIString(std::string v, int xP, int yP, int s) {
	strings.push_back(UIString(v, xP, yP, texture, font, s));
	strings.back().setAlignment(UIString::UIString_alignment::left);
}

void UIElementManager::addUIString(std::string v, int xP, int yP, int s, UIString::UIString_alignment a) {
	strings.push_back(UIString(v, xP, yP, texture, font, s));
	strings.back().setAlignment(a);
}

void UIElementManager::addButton() {

}