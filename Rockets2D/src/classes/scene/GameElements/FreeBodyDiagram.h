#pragma once
#include "../../game/FreeBody.h"
#include "../UIElements/UIElement.h"
#include "../Misc/Arrow.h"

class FreeBodyDiagram : public UIElement
{
public:
	FreeBodyDiagram(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, int s, FreeBody* ptr, bool* canD, long double* o);
	void update() override;
	void synchronousUpdate() override;
	void forceToArrow();
private:
	FreeBody* fbdPtr = nullptr;
	long double* orientation = nullptr;
	bool* canDraw = nullptr;
	sf::CircleShape body;
	std::vector<Arrow> arrows;
	int size = 0;
};