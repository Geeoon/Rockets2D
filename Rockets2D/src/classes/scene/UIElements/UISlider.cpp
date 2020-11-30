#include "UISlider.h"

UISlider::UISlider(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, int len, long double* oVal, sf::Sound* cl, sf::Sound* uCl) : UIElement(t, w, xP, yP) {
	sliderLength = len;
	outputValue = oVal;
	*outputValue = 0;
	x = xP;
	y = yP;
	click = cl;
	unClick = uCl;
	slider.setFillColor(fillColor);
	slider.setOutlineColor(accentColor);
	slider.setOutlineThickness(2.0f);
	slider.setSize(sf::Vector2f(8.0f, 20.0f));
	slider.setOrigin(sf::Vector2f((float)(slider.getGlobalBounds().width / 2 - 2), (float)(slider.getGlobalBounds().height / 2 - 3)));
	slider.setPosition((float)(x + *outputValue / sliderLength), (float)y);
	bar.setFillColor(accentColor);
	bar.setSize(sf::Vector2f((float)sliderLength, 2.0f));
	bar.setOrigin(0.0f, 0.0f);
	bar.setPosition((float)x, (float)y);
}

void UISlider::update() {
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (beingSlid == true) {
			*outputValue = (long double)((texture->mapPixelToCoords(sf::Mouse::getPosition(*window)).x - (float)x) / (float)sliderLength) * 100.0f;
			if (*outputValue < 0) {
				*outputValue = 0;
			} else if (*outputValue > 100) {
				*outputValue = 100;
			}
		} else if (slider.getGlobalBounds().contains(texture->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
			beingSlid = true;
			click->play();
		}
	} else {
		if (beingSlid == true) {
			beingSlid = false;
			unClick->play();
		}
	}

	slider.setPosition((float)((long double)x + *outputValue / 100 * sliderLength), (float)y);
	texture->draw(bar);
	texture->draw(slider);
}