#pragma once
#include "../../game/FreeBody.h"
#include "../UIElements/UIElement.h"
#include "../Misc/Arrow.h"

class FreeBodyDiagram : public UIElement
{
public:
	FreeBodyDiagram(sf::RenderTexture* t, sf::RenderWindow* w, int xP, int yP, int s, FreeBody* ptr);
	void update() override;
	void synchronousUpdate() override;
	void forceToArrow();
private:
	FreeBody* fbdPtr;
	sf::CircleShape body;
	std::vector<Arrow> arrows;
	int size = 0;
};