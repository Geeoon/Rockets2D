#include "FreeBodyDiagram.h"
#define M_PI 3.14159265358979323846264338327950288

FreeBodyDiagram::FreeBodyDiagram(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, int s, FreeBody* ptr) : UIElement(t, w, xP, yP) {
	fbdPtr = ptr;
	size = s;
	body.setRadius(size / 10);
	body.setPointCount(50);
	body.setOrigin(sf::Vector2f(body.getLocalBounds().height / 2, body.getLocalBounds().height / 2));
	body.setPosition(sf::Vector2f(x, y));
	body.setFillColor(sf::Color::Black);
	body.setOutlineThickness(2);
	body.setOutlineColor(sf::Color(0, 255, 65));
}

void FreeBodyDiagram::update() {
	texture->draw(body);
	for (Arrow arrow : arrows) {
		arrow.draw(texture);
	}
	
}

void FreeBodyDiagram::synchronousUpdate() { 
	forceToArrow();
}

void FreeBodyDiagram::forceToArrow() {
	arrows.clear();
	long double maxForce = 0;
	
	for (Vector2 force : fbdPtr->getForces()) {
		if (maxForce < force.getMagnitude()) {
			maxForce = force.getMagnitude();
		}
	}

	for (Vector2 force : fbdPtr->getForces()) {
		arrows.push_back(Arrow(force.getMagnitude() / maxForce * ((long double)size - (long double)10), 10, x, y, (-force.getAngle() * 180 / M_PI) - 90));
	}
	
}