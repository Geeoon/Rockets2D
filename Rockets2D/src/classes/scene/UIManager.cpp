#include "UIManager.h"

UIManager::UIManager() {
	videoSettings.antialiasingLevel = 0;
	window.create(sf::VideoMode(800, 800), "Rockets2D", sf::Style::Close, videoSettings);
	window.setFramerateLimit(300);
	if (!(uiTexture.create(window.getSize().x, window.getSize().y, videoSettings) && gameTexture.create(window.getSize().x, window.getSize().y, videoSettings))) {
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
	mainMenu->addPage(); //main menu page 0
	mainMenu->addUIString(0, "Rockets2D", uiTexture.getSize().x / 2, 25, 30, UIString::UIString_alignment::center);
	mainMenu->addButton(0, "Start", 25, 75, 20, [&] {play(); });
	mainMenu->addButton(0, "Controls", 25, 125, 20, [&] {controls(); });
	mainMenu->addButton(0, "Credits", 25, 175, 20, [&] {credits(); });
	mainMenu->addButton(0, "Quit", 25, 225, 20, [&] {quit(); });
	
	mainMenu->addPage(); //credits page 1
	mainMenu->addUIString(1, "Rockets2D", uiTexture.getSize().x / 2, 25, 30, UIString::UIString_alignment::center);
	mainMenu->addUIString(1, "Credits", uiTexture.getSize().x / 2, 60, 20, UIString::UIString_alignment::center);
	mainMenu->addUIString(1, "Created by Geeoon Chung \nUI Sounds provided by Octave http://raisedbeaches.com/octave/ \nGraphics library provided by SFML https://www.sfml-dev.org/ \nPhysics engine provided by Box2D https://box2d.org/", 25, 100, 15);
	mainMenu->addButton(1, "<- Back", 25, 25, 20, [&] {mainMenu->setActivePage(0); });
	
	mainMenu->addPage(); //controls page 2
	mainMenu->addUIString(2, "Rockets2D", uiTexture.getSize().x / 2, 25, 30, UIString::UIString_alignment::center);
	mainMenu->addUIString(2, "Controls", uiTexture.getSize().x / 2, 60, 20, UIString::UIString_alignment::center);
	mainMenu->addUIString(2, "No controls implimented yet.", 25, 100, 15);
	mainMenu->addButton(2, "<- Back", 25, 25, 20, [&] {mainMenu->setActivePage(0); });
	mainMenu->setActive(true);

	gameUI = std::make_unique<UIElementManagerGroup>(&uiTexture, &window, &font, &hover, &click, &unClick);
	gameUI->addPage(); //standard non-pause game
	gameUI->addUIString(0, "Position: (x), (y) relative to [selected object]", 0, uiTexture.getSize().y, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::bottom);
	gameUI->setActive(false);
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
	gameUI->update();
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
	gameUI->setActive(true);
}

void UIManager::controls() {
	mainMenu->setActivePage(2);
}

void UIManager::credits() {
	mainMenu->setActivePage(1);
}

void UIManager::quit() {
	window.close();
}