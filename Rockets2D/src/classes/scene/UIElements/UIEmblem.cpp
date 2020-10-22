#include "UIEmblem.h"

UIEmblem::UIEmblem(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, std::string titl, std::string d, sf::Font* f) : UIElement(t, w, xP, yP) {
	sprite.setFillColor(sf::Color::Black);
	sprite.setOutlineColor(sf::Color(0, 255, 65));
	sprite.setOrigin((float)sprite.getLocalBounds().width / 2, (float)sprite.getLocalBounds().height / 2);
	sprite.setOutlineThickness(4);
	sprite.setRadius(15);
	sprite.setPosition(300, 300);
	//description = std::make_unique<UIString>(t, w, xP, yP);
	//title = std::make_unique<UIString>(t, w, xP, yP);
}

void UIEmblem::update() {
	texture->draw(sprite);
}