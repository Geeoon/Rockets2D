#include "Arrow.h"

Arrow::Arrow(int l, int w, int xP, int yP, long double a) {
	length = l;
	width = w;
	x = xP;
	y = yP;
	angle = a;
	arrowHead.setPointCount(3);
	arrowHead.setRadius(width / 2);
	arrowHead.setFillColor(sf::Color::Black);
	arrowHead.setOrigin(arrowHead.getLocalBounds().width / 2, length);
	arrowHead.setPosition(x, y);
	arrowHead.setRotation(a);
	arrowHead.setOutlineThickness(2);
	arrowHead.setOutlineColor(sf::Color(0, 255, 65));
	body.setSize(sf::Vector2f(2, length));
	body.setOrigin(body.getLocalBounds().width / 2, length);
	body.setFillColor(sf::Color(0, 255, 65));
	body.setPosition(x, y);
	body.setRotation(a);
}

void Arrow::setLength(int l) {
	length = l;
	arrowHead.setOrigin(arrowHead.getLocalBounds().width / 2, length);
	body.setSize(sf::Vector2f(2, length));
	body.setOrigin(body.getLocalBounds().width / 2, length);
}

void Arrow::setAngle(int a) {
	angle = a;
	arrowHead.setRotation(a);
	body.setRotation(a);
}

void Arrow::draw(sf::RenderTexture* rt) {
	rt->draw(body);
	rt->draw(arrowHead);

}

void Arrow::setDirection(bool d) {
	if (d) {
		arrowHead.setOrigin(-arrowHead.getLocalBounds().width / 4 - 2, arrowHead.getRadius());
		arrowHead.setRadius(-arrowHead.getRadius());
	} else {
		arrowHead.setOrigin(arrowHead.getLocalBounds().width / 2 - 2, length - arrowHead.getRadius());
		setAngle(angle+180);
	}
}