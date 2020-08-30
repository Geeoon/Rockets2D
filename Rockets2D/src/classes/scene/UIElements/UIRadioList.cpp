#include "UIRadioList.h"

UIRadioList::UIRadioList(type typ, sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, sf::Font* f, int s, std::string args[]) : UIElement(t, w, xP, yP) {
	font = f;
	textSize = s;
	for (int i = 0; i < sizeof(args); i++) {
		radios.push_back(UIRadio(texture, window, x, y, args[i], font, textSize));
	}
}

void UIRadioList::update() {
	for (UIRadio& radio : radios) {
		radio.update();
	}

	for (UIRadio& radio : radios) {
		if (currentOn != radio.getIsOnPtr() && *(radio.getIsOnPtr()) == true) {
			if (currentOn != nullptr) {
				*currentOn = false;
			}
			currentOn = radio.getIsOnPtr();
		}
	}
}

void UIRadioList::addRadio(std::string v) {
	radios.push_back(UIRadio(texture, window, x, y, v, font, textSize));
}