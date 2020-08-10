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
	slider.setOutlineThickness(2);
	slider.setSize(sf::Vector2f(8, 20));
	slider.setOrigin(sf::Vector2f(slider.getGlobalBounds().width / 2 - 2, slider.getGlobalBounds().height / 2 - 3));
	slider.setPosition(x + *outputValue / sliderLength, y);
	bar.setFillColor(accentColor);
	bar.setSize(sf::Vector2f(sliderLength, 2));
	bar.setOrigin(0, 0);
	bar.setPosition(x, y);

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

	slider.setPosition(x + *outputValue / 100 * sliderLength, y);
	texture->draw(bar);
	texture->draw(slider);
}