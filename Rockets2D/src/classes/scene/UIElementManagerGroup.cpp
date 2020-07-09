#include "UIElementManagerGroup.h"

UIElementManagerGroup::UIElementManagerGroup(sf::RenderTexture* t, sf::RenderWindow* w, sf::Font* f, sf::Sound* ho, sf::Sound* cl, sf::Sound* uCl) {
	texture = t;
	window = w;
	font = f;
	hover = ho;
	click = cl;
	unClick = uCl;
}

void UIElementManagerGroup::addPage() {
	pages.push_back(UIElementManager(texture, window, font, hover, click, unClick));
}

void UIElementManagerGroup::addButton(int page, std::string v, int xP, int yP, int s, const std::function<void()>& m) {
	pages[page].addButton(v, xP, yP, s, m);
}

void UIElementManagerGroup::addUIString(int page, std::string v, int xP, int yP, int s) {
	pages[page].addUIString(v, xP, yP, s);
}

void UIElementManagerGroup::addUIString(int page, std::string v, int xP, int yP, int s, UIString::UIString_alignment a) {
	pages[page].addUIString(v, xP, yP, s);
	pages[page].getLastString().setAlignment(a);
}

void UIElementManagerGroup::setActive(bool active) {
	isActive = active;
	for (int i = 0; i < pages.size(); i++) {
		if (i == 0) {
			pages[i].setActive(true);
		} else {
			pages[i].setActive(false);
		}
	}
}

void UIElementManagerGroup::update() {
	if (isActive) {
		for (UIElementManager& page : pages) {
			page.update();
		}
	}
}

void UIElementManagerGroup::setActivePage(int page) {
	if (page < pages.size()) {
		for (int i = 0; i < pages.size(); i++) {
			if (page == i) {
				pages[i].setActive(true);
			} else {
				pages[i].setActive(false);
			}
		}
	} else {
		std::cout << "ERROR SETTING ACTIVE PAGE";
	}
}