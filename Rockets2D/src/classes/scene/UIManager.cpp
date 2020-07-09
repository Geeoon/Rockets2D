#include "UIManager.h"

UIManager::UIManager() {
	videoSettings.antialiasingLevel = 0;
	window.create(sf::VideoMode(800, 800), "Rockets2D", sf::Style::Close, videoSettings);
	window.setFramerateLimit(300);
	if (!(uiTexture.create(800, 800, videoSettings) && gameTexture.create(800, 800, videoSettings))) {
		//check for if there is an error creating the gameTexture or the uiTexture
	}
	font.loadFromFile("fonts/SourceCodePro.ttf");
	hoverB.loadFromFile("sounds/ui/hover.wav");
	clickB.loadFromFile("sounds/ui/click.wav");
	unClickB.loadFromFile("sounds/ui/unClick.wav");
	hover.setBuffer(hoverB);
	click.setBuffer(clickB);
	unClick.setBuffer(unClickB);
	mainMenu = std::make_unique<UIElementManagerGroup>(&uiTexture, &window, &font, &hover, &click, &unClick);
	mainMenu->addPage();
	mainMenu->addUIString(0, "Rockets2D", gameTexture.getSize().x / 2, 25, 50, UIString::UIString_alignment::center);
	mainMenu->addButton(0, "Start", 25, 75, 20, [&] {play(); });
	mainMenu->addButton(0, "Credits", 25, 125, 20, [&] {credits(); });
	mainMenu->addButton(0, "Quit", 25, 175, 20, [&] {quit(); });
	mainMenu->setActive(true);
}

void UIManager::update() {
	updateUI();
	pollEvent();
	window.clear(sf::Color::Black);
	window.draw(sf::Sprite(gameTexture.getTexture())); //first the game,
	window.draw(sf::Sprite(uiTexture.getTexture())); //then the ui; this keeps the UI always on top no matter what.
	window.display();
}

sf::RenderTexture* UIManager::getGameTexture() {
	return &gameTexture;
}

bool UIManager::isOpen() {
	return window.isOpen();
}

void UIManager::updateUI() {
	uiTexture.clear(sf::Color::Black);
	mainMenu->update();
	uiTexture.display();
}

void UIManager::pollEvent() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void UIManager::play() {
	mainMenu->setActive(false);
}

void UIManager::credits() {

}

void UIManager::quit() {
	window.close();
}