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
	pages.push_back(std::make_unique<UIElementManager>(texture, window, font, hover, click, unClick)); //this line doesn't work on my desktop but works on my laptop.
}

void UIElementManagerGroup::addButton(int page, std::string v, int xP, int yP, int s, const std::function<void()>& m) {
	pages[page]->addButton(v, xP, yP, s, m);
}

void UIElementManagerGroup::addUIString(int page, std::string v, int xP, int yP, int s) {
	pages[page]->addUIString(v, xP, yP, s);
}

void UIElementManagerGroup::addUIString(int page, std::string v, int xP, int yP, int s, UIString::UIString_alignment a) {
	pages[page]->addUIString(v, xP, yP, s, a);
}

void UIElementManagerGroup::addUIString(int page, std::string v, int xP, int yP, int s, UIString::UIString_alignment a, UIString::UIString_alignment a2) {
	pages[page]->addUIString(v, xP, yP, s, a, a2);
}

void UIElementManagerGroup::addBackground(int page, int xP, int yP, int wid, int hei) {
	pages[page]->addBackground(xP, yP, wid, hei);
}

void UIElementManagerGroup::addSlider(int page, int xP, int yP, int len, long double* oVal) {
	pages[page]->addSlider(xP, yP, len, oVal);
}

void UIElementManagerGroup::addFBD(int page, int xP, int yP, int s, FreeBody* fb, bool* canD) {
	pages[page]->addFBD(xP, yP, s, fb, canD);
}

void UIElementManagerGroup::addRadioList(int page, int xP, int yP, int s, std::string args[], size_t num) {
	pages[page]->addRadioList(xP, yP, s, args, num);
}

void UIElementManagerGroup::addRadioList(int page, int xP, int yP, int s, std::string args[], size_t num, int def) {
	pages[page]->addRadioList(xP, yP, s, args, num, def);
}

void UIElementManagerGroup::addEmblem(int page, sf::RenderTexture* t2, long double* xP, long double* yP, std::string titl, std::string d) {
	pages[page]->addEmblem(t2, xP, yP, titl, d);
}

void UIElementManagerGroup::setActive(bool active) {
	isActive = active;
	for (size_t i = 0; i < pages.size(); i++) {
		if (i == 0) {
			pages[i]->setActive(true);
		} else {
			pages[i]->setActive(false);
		}
	}
}

void UIElementManagerGroup::update() {
	if (isActive) {
		for (std::unique_ptr<UIElementManager>& page : pages) {
			page->update();
		}
	}
}

void UIElementManagerGroup::synchronousUpdate() {
	if (isActive) {
		for (std::unique_ptr<UIElementManager>& page : pages) {
			page->synchronousUpdate();
		}
	}
}

void UIElementManagerGroup::setActivePage(size_t page) {
	if (page < pages.size()) {
		for (size_t i = 0; i < pages.size(); i++) {
			if (page == i) {
				pages[i]->setActive(true);
			} else {
				pages[i]->setActive(false);
			}
		}
	} else {
		std::cout << "ERROR SETTING ACTIVE PAGE";
	}
}