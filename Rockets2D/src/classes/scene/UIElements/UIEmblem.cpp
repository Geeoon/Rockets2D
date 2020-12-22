#include "UIEmblem.h"

UIEmblem::UIEmblem(sf::RenderTexture* t, sf::RenderTexture* t2, sf::RenderWindow* w, long double* xP, long double* yP, std::string titl, std::string d, sf::Font* f, type shape, long double* aPtr, long double r) : UIElement(t, w, *xP, *yP), 
texture2{ t2 },
xPointer { xP },
yPointer { yP },
radius{ r } {
	if (!(xP && yP && f)) {
		throw std::invalid_argument{ "nullptr exception" };
	}
	sprite.setFillColor(sf::Color::Black);
	sprite.setOutlineColor(sf::Color(0, 255, 65));
	sprite.setOrigin((float)sprite.getLocalBounds().width / 2, (float)sprite.getLocalBounds().height / 2);
	sprite.setOutlineThickness((3 * texture->getView().getSize().x / texture->getSize().x < 1) ? 1 : (3 * texture->getView().getSize().x / texture->getSize().x));
	sprite.setRadius(8);
	anglePointer = aPtr;
	sprite.setPosition((float)*xP, (float)*yP);
	switch (shape) {
		case (type::CIRCLE): {

		} break;
		case (type::SQUARE): {
			sprite.setPointCount(4);
		} break;
		case (type::TRIANGLE): {
			sprite.setPointCount(3);
		} break;
		default: {
		
		}
	}
	title = std::make_unique<UIString>(texture2, w, (int)*xP, (int)*yP, titl, f, 20);
	description = std::make_unique<UIString>(texture2, w, (int)*xP, (int)*yP, d, f, 10);
	int width = title->getBounds().width;
	int height = title->getBounds().height;
	if (width < description->getBounds().width) {
		width = (int)description->getBounds().width;
	}
	height += (int)description->getBounds().height + 25;
	width += 8;
	background = std::make_unique<UIBackground>(texture2, w, (int)*xP, (int)*yP, width, height);
	background->setCenter(0, 0);
}

void UIEmblem::update() {
	sprite.setPosition((float)*xPointer, -(float)*yPointer);
	float relSize = texture->getView().getSize().x / texture->getSize().x;
	if (sprite.getPointCount() == 3) {
		sprite.setRadius(radius * relSize);
	} else {
		sprite.setRadius(radius);
	}sprite.setOrigin((float)sprite.getLocalBounds().width / 2, (float)sprite.getLocalBounds().height / 2);
	sprite.setOutlineThickness((3 * relSize < 1) ? 1 : (3 * relSize));
	if (anglePointer != nullptr) {
		sprite.setRotation((float)*anglePointer * 180.0F / (float)M_PI);
	}
	texture->draw(sprite);
	if (sprite.getGlobalBounds().contains(texture->mapPixelToCoords(sf::Mouse::getPosition(*window)))) {
		sf::Vector2i temp = texture->mapCoordsToPixel(sf::Vector2f((float)*xPointer, -(float)*yPointer));
		title->setPos(temp.x + 10, temp.y + 10);
		description->setPos(temp.x + 10, temp.y + 30);
		background->setPos(temp.x + 10, temp.y + 10);
		background->update();
		title->update();
		description->update();
	}
}