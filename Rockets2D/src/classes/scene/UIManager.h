#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "../game/Game.h"
#include "UIElementManagerGroup.h"

class UIManager
{
public:
	UIManager();
	void update();
	sf::RenderTexture* getGameTexture();
	sf::RenderTexture* getFBTexture();
	bool isOpen();
	void setGame(std::shared_ptr<Game> g);
private:
	std::shared_ptr<Game> game;
	sf::RenderWindow window; //for texture and ui elements to be rendered together
	sf::RenderTexture uiTexture; //for the UI itself
	sf::RenderTexture gameTexture; //for the scene itself only.
	sf::RenderTexture freeBodyTexture; //for the free body diagram
	sf::ContextSettings videoSettings;
	std::unique_ptr<UIElementManagerGroup> mainMenu;
	std::unique_ptr<UIElementManagerGroup> gameUI;
	sf::Font font;
	sf::SoundBuffer hoverB;
	sf::SoundBuffer clickB;
	sf::SoundBuffer unClickB;
	sf::Sound hover;
	sf::Sound click;
	sf::Sound unClick;
	sf::View gameView;
	void updateUI();
	void pollEvent();
	void play();
	void controls();
	void credits();
	void quit();
	void quitGame();
};

