#include "Button.h"

Button::Button(sf::RenderTexture* t, sf::RenderWindow* w, const std::function<void()>& m, int s, std::string v, sf::Font* f, int xP, int yP, sf::Sound* ho, sf::Sound* cl) {
	texture = t;
	window = w;
	onClick = m;
	textSize = s;
	value = v;
	font = f;
	x = xP;
	y = yP;
	hover = ho;
	click = cl;
	textColor = sf::Color(0, 255, 65);
	backgroundColor = sf::Color(0, 255, 65, 0);
	borderColor = sf::Color(0, 255, 65);
	reset();
}

void Button::update() {
	if (button.getGlobalBounds().contains(texture->mapPixelToCoords(sf::Mouse::getPosition(*window)))) { 		
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { //click
			click->play();
			onClick();
		} else { //hover			
			if (borderColor != sf::Color(150, 255, 150) || textColor != sf::Color(150, 255, 150)) {
				hover->play();
				borderColor = sf::Color(150, 255, 150);
				textColor = sf::Color(150, 255, 150);
				hasChanged = true;
			}
		}
	} else { //mouse not over button
		if (borderColor != sf::Color(0, 255, 65) || textColor != sf::Color(0, 255, 65) || backgroundColor != sf::Color(0, 255, 65)) {
			textColor = sf::Color(0, 255, 65);
			backgroundColor = sf::Color(0, 255, 65, 0);
			borderColor = sf::Color(0, 255, 65);
			hasChanged = true;
		}
	}
	if (hasChanged) {
		reset();
		hasChanged = false;
	}
	texture->draw(button);
	texture->draw(text);
}

void Button::reset() {
	text.setCharacterSize(textSize);
	text.setFont(*font);
	text.setFillColor(textColor);
	text.setPosition((float)x + font->getLineSpacing(textSize) / 3.1, (float)y);
	text.setString(value);
	text.setOrigin(0, 0);
	button.setSize(sf::Vector2f(font->getLineSpacing(textSize) * 3.1, font->getLineSpacing(textSize)));
	button.setPosition((float)x, (float)y);
	button.setOutlineThickness(2);
	button.setOutlineColor(borderColor);
	button.setFillColor(backgroundColor);
	button.setOrigin(0, 0);
}