#include "UIManager.h"

UIManager::UIManager() {
	videoSettings.antialiasingLevel = 0;
	window.create(sf::VideoMode(800, 800), "Rockets2D", sf::Style::Close, videoSettings);
	window.setFramerateLimit(300);
	if (!(uiTexture.create(800, 800, videoSettings) && gameTexture.create(800, 800, videoSettings))) {
		//runs when there is an error creating the gameTexture or the uiTexture
	}
	font.loadFromFile("fonts/SourceCodePro.ttf");
	testUI = std::make_unique<UIElementManager>(&uiTexture, &window, &font);
	testUI->addUIString("Hello World", 100, 100, 20);
	testUI->setActive(true);
}

void UIManager::update() {
	updateUI();
	window.clear(sf::Color::Black);
	window.draw(sf::Sprite(gameTexture.getTexture())); //first the game,
	window.draw(sf::Sprite(uiTexture.getTexture())); //then the ui; this keeps the UI always on top no matter what.
	window.display();
}

sf::RenderTexture* UIManager::getGameTexture() {
	return &gameTexture;
}

void UIManager::updateUI() {
	uiTexture.clear(sf::Color::Black);
	testUI->update();
	uiTexture.display();
}