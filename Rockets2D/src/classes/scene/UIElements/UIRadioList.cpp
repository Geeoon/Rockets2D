#include "UIRadioList.h"

UIRadioList::UIRadioList(type typ, sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, sf::Font* f, int s, std::string args[], size_t num) : UIElement(t, w, xP, yP) {
	font = f;
	textSize = s;
	for (int i = 0; i < num; i++) {
		int xOffset = 0;
		for (int j = 0; j < i; j++) {
			xOffset += f->getGlyph(65, s, false, 0).bounds.width * (args[j].length() + 4);
		}
		radios.push_back(UIRadio(texture, window, x + xOffset, y, args[i], font, textSize));
	}
}

UIRadioList::UIRadioList(type typ, sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, sf::Font* f, int s, std::string args[], size_t num, int def) : UIElement(t, w, xP, yP) {
	font = f;
	textSize = s;
	for (int i = 0; i < num; i++) {
		int xOffset = 0;
		for (int j = 0; j < i; j++) {
			xOffset += f->getGlyph(65, s, false, 0).bounds.width * (args[j].length() + 4);
		}
		radios.push_back(UIRadio(texture, window, x + xOffset, y, args[i], font, textSize));
	}
	*(radios[def].getIsOnPtr()) = true;
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

std::vector<bool*> UIRadioList::getBoolPtrArr() {
	std::vector<bool*> bArray;
	for (UIRadio& radio : radios) {
		bArray.push_back(radio.getIsOnPtr());
	}
	return bArray;
}