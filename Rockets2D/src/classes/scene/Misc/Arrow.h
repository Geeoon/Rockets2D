#pragma once
#include <SFML/Graphics.hpp>
class Arrow
{
public:
	Arrow(int l, int w, int xP, int yP, long double a);

	void setLength(int l);

	void setAngle(int a);

	void draw(sf::RenderTexture* rt);

private:
	sf::CircleShape arrowHead;
	sf::RectangleShape body;
	int length = 0;
	int width = 0;
	int x = 0;
	int y = 0;
	long double angle = 0;
};