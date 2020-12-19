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

void UIElementManager::synchronousUpdate() {
	if (active) {
		for (std::shared_ptr<UIElement> element : elements) {
			element->synchronousUpdate();
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

void UIElementManager::addBackground(int xP, int yP, int wid, int hei) {
	elements.insert(elements.begin(), std::make_shared<UIBackground>(texture, window, xP, yP, wid, hei)); //must be inserted at the beginning as elements are drawn in order of position in vector
}

void UIElementManager::addSlider(int xP, int yP, int len, long double* oVal) {
	elements.push_back(std::make_shared<UISlider>(texture, window, xP, yP, len, oVal, click, unClick));
}

void UIElementManager::addFBD(int xP, int yP, int s, FreeBody* fb, bool* canD, long double* o) {
	elements.push_back(std::make_shared<FreeBodyDiagram>(texture, window, xP, yP, s, fb, canD, o));
}

void UIElementManager::addRadioList(int xP, int yP, int s, std::string args[], size_t num) {
	elements.push_back(std::make_shared<UIRadioList>(UIRadioList::type::vertical, texture, window, xP, yP, font, s, args, num));
}

void UIElementManager::addRadioList(int xP, int yP, int s, std::string args[], size_t num, int def) {
	elements.push_back(std::make_shared<UIRadioList>(UIRadioList::type::vertical, texture, window, xP, yP, font, s, args, num, def));
}

void UIElementManager::addEmblem(sf::RenderTexture* t2, long double* xP, long double* yP, std::string titl, std::string d, UIEmblem::type shape, long double* aPtr) {
	elements.push_back(std::make_shared<UIEmblem>(texture, t2, window, xP, yP, titl, d, font, shape, aPtr));
}