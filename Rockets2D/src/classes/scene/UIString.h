#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class UIString
{
public:
	UIString(std::string v, int xP, int yP, sf::RenderTexture* t, sf::Font& f, int s);
	void update();
	void setVal(std::string v);
	void setPos(int xP, int yP);
	void setFont(sf::Font& f);
	void setSize(int s);
	void setColor(sf::Color c);

private:
	int x;
	int y;
	int size;
	std::string value;
	sf::RenderTexture* texture;
	sf::Font font;
	sf::Color color;
};

