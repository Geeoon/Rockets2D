#pragma once
#include "../../game/FreeBody.h"
#include "../UIElements/UIElement.h"
#include "../Misc/Arrow.h"

class FreeBodyDiagram : public UIElement
{
public:
	FreeBodyDiagram(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, int s, FreeBody* ptr, bool* canD);
	void update() override;
	void synchronousUpdate() override;
	void forceToArrow();
private:
	FreeBody* fbdPtr = nullptr;
	bool* canDraw = nullptr;
	sf::CircleShape body;
	std::vector<Arrow> arrows;
	int size = 0;
};