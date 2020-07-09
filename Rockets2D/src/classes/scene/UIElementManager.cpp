#include "UIElementManager.h"

UIElementManager::UIElementManager(sf::RenderTexture* t, sf::RenderWindow* w, sf::Font* f, sf::Sound* ho, sf::Sound* cl, sf::Sound* uCl) {
	texture = t;
	window = w;
	font = f;
	hover = ho;
	click = cl;
	unClick = uCl;
}

void UIElementManager::update() {
	if (active) {
		for (UIString& string : strings) {
			string.draw();
		}

		for (Button& button : buttons) {
			button.update();
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

void UIElementManager::addButton(std::string v, int xP, int yP, int s, const std::function<void()>& m) {
	buttons.push_back(Button(texture, window, m, s, v, font, xP, yP, hover, click, unClick));
}

UIString& UIElementManager::getLastString() {
	return strings.back();
}