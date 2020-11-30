#include "Arrow.h"

Arrow::Arrow(int l, int w, int xP, int yP, long double a) {
	length = l;
	width = w;
	x = xP;
	y = yP;
	angle = a;
	arrowHead.setPointCount(3);
	arrowHead.setRadius((float)width / 2);
	arrowHead.setFillColor(sf::Color::Black);
	arrowHead.setOrigin(arrowHead.getLocalBounds().width / 2, (float)length);
	arrowHead.setPosition((float)x, (float)y);
	arrowHead.setRotation((float)a);
	arrowHead.setOutlineThickness(2);
	arrowHead.setOutlineColor(sf::Color(0, 255, 65));
	body.setSize(sf::Vector2f(2, (float)length));
	body.setOrigin(body.getLocalBounds().width / 2, (float)length);
	body.setFillColor(sf::Color(0, 255, 65));
	body.setPosition((float)x, (float)y);
	body.setRotation((float)a);
}

void Arrow::setLength(int l) {
	length = l;
	arrowHead.setOrigin(arrowHead.getLocalBounds().width / 2, (float)length);
	body.setSize(sf::Vector2f(2, (float)length));
	body.setOrigin(body.getLocalBounds().width / 2, (float)length);
}

void Arrow::setAngle(int a) {
	angle = a;
	arrowHead.setRotation((float)a);
	body.setRotation((float)a);
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
		setAngle((int)angle+180);
	}
}