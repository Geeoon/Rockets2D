#include "UIEmblem.h"

UIEmblem::UIEmblem(sf::RenderTexture* t, sf::RenderTexture* t2, sf::RenderWindow* w, long double* xP, long double* yP, std::string titl, std::string d, sf::Font* f) : UIElement(t, w, *xP, *yP) {
	sprite.setFillColor(sf::Color::Black);
	sprite.setOutlineColor(sf::Color(0, 255, 65));
	sprite.setOrigin((float)sprite.getLocalBounds().width / 2, (float)sprite.getLocalBounds().height / 2);
	sprite.setOutlineThickness((3 * texture->getView().getSize().x / texture->getSize().x < 1) ? 1 : (3 * texture->getView().getSize().x / texture->getSize().x));
	sprite.setRadius(8);
	xPointer = xP;
	yPointer = yP;
	sprite.setPosition((float)*xP, (float)*yP);
	texture2 = t2;
	title = std::make_unique<UIString>(texture2, w, (int)*xP, (int)*yP, titl, f, 20);
	description = std::make_unique<UIString>(texture2, w, (int)*xP, (int)*yP, d, f, 10);
	int width = title->getBounds().width;
	int height = title->getBounds().height;
	if (width < description->getBounds().width) {
		width = description->getBounds().width;
	}
	height += description->getBounds().height + 25;
	width += 8;
	background = std::make_unique<UIBackground>(texture2, w, (int)*xP, (int)*yP, width, height);
	background->setCenter(0, 0);
}

void UIEmblem::update() {
	sprite.setPosition((float)*xPointer, (float)*yPointer);
	double relSize = texture->getView().getSize().x / texture->getSize().x;
	sprite.setRadius(10 * relSize);
	sprite.setOrigin((float)sprite.getLocalBounds().width / 2, (float)sprite.getLocalBounds().height / 2);
	sprite.setOutlineThickness((3 * relSize < 1) ? 1 : (3 * relSize));
	texture->draw(sprite);
	if (sprite.getGlobalBounds().contains(texture->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
		//std::cout << texture->mapPixelToCoords(sf::Mouse::getPosition(*window)).x << std::endl;
		sf::Vector2i temp = texture->mapCoordsToPixel(sf::Vector2f((float)*xPointer, (float)*yPointer));
		title->setPos(temp.x + 10, temp.y + 10);
		description->setPos(temp.x + 10, temp.y + 30);
		background->setPos(temp.x + 10, temp.y + 10);
		background->update();
		title->update();
		description->update();
	}
}