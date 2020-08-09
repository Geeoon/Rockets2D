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
		for (std::shared_ptr<UIElement> element : elements) {
			element->update();
		}
	}
}

void UIElementManager::setActive(bool a) {
	active = a;
}

void UIElementManager::addUIString(std::string v, int xP, int yP, int s) {
	elements.push_back(std::make_shared<UIString>(texture, window, xP, yP, v, font, s, UIString::UIString_alignment::left));
}

void UIElementManager::addUIString(std::string v, int xP, int yP, int s, UIString::UIString_alignment a) {
	elements.push_back(std::make_shared<UIString>(texture, window, xP, yP, v, font, s, a));
}

void UIElementManager::addUIString(std::string v, int xP, int yP, int s, UIString::UIString_alignment a, UIString::UIString_alignment a2) {
	elements.push_back(std::make_shared<UIString>(texture, window, xP, yP, v, font, s, a, a2));
}

void UIElementManager::addButton(std::string v, int xP, int yP, int s, const std::function<void()>& m) {
	elements.push_back(std::make_shared<Button>(texture, window, xP, yP, m, s, v, font, hover, click, unClick));
}