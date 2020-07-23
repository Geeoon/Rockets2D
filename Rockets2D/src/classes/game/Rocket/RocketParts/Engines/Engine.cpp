#include "Engine.h"

Engine::Engine(sf::RenderTexture* t, const Vector2& pos, long double m) : RocketPart(t, pos, m) {
	mass = 10;
	thrust = 1;
	nozzle.setFillColor(fillColor);
	nozzle.setOutlineColor(borderColor);
	nozzle.setOutlineThickness(3);
	throat.setFillColor(fillColor);
	throat.setOutlineColor(borderColor);
	throat.setOutlineThickness(3);
	base.setFillColor(fillColor);
	base.setOutlineColor(borderColor);
	base.setOutlineThickness(3);
}