#include "UIEmblem.h"

UIEmblem::UIEmblem(sf::RenderTexture* t, sf::RenderWindow* w, long double* xP, long double* yP, std::string titl, std::string d, sf::Font* f) : UIElement(t, w, *xP, *yP) {
	sprite.setFillColor(sf::Color::Black);
	sprite.setOutlineColor(sf::Color(0, 255, 65));
	sprite.setOrigin((float)sprite.getLocalBounds().width / 2, (float)sprite.getLocalBounds().height / 2);
	sprite.setOutlineThickness((3 * texture->getView().getSize().x / texture->getSize().x < 1) ? 1 : (3 * texture->getView().getSize().x / texture->getSize().x));
	sprite.setRadius(8);
	xPointer = xP;
	yPointer = yP;
	sprite.setPosition((float)*xP, (float)*yP);
	//description = std::make_unique<UIString>(t, w, xP, yP);
	//title = std::make_unique<UIString>(t, w, xP, yP);
}

void UIEmblem::update() {
	sprite.setPosition((float)*xPointer, (float)*yPointer);
	sprite.setRadius(10 * texture->getView().getSize().x / texture->getSize().x);
	sprite.setOrigin((float)sprite.getLocalBounds().width / 2, (float)sprite.getLocalBounds().height / 2);
	sprite.setOutlineThickness((3 * texture->getView().getSize().x / texture->getSize().x < 1) ? 1 : (3 * texture->getView().getSize().x / texture->getSize().x));
	texture->draw(sprite);
	std::cout << (float)*xPointer << std::endl;
}