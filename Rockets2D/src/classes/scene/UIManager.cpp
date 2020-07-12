#include "UIManager.h"

UIManager::UIManager() {
	videoSettings.antialiasingLevel = 0;;
	window.create(sf::VideoMode(800, 800), "Rockets2D", sf::Style::Close, videoSettings);
	window.setFramerateLimit(300);
	freeBodyTexture.create(150, 150);
	if (!(uiTexture.create(window.getSize().x, window.getSize().y, videoSettings) && gameTexture.create(window.getSize().x, window.getSize().y, videoSettings))) {
		//check for if there is an error creating the gameTexture or the uiTexture
	}
	gameView = gameTexture.getView();
	gameView.setCenter(gameTexture.getSize().x / 2, gameTexture.getSize().y / 2);
	gameView.move(-((signed)gameTexture.getSize().x / 2), -((signed)gameTexture.getSize().y / 2));
	gameTexture.setView(gameView);
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
	gameUI->addUIString(0, "Free Body Diagram", uiTexture.getSize().x - 10, uiTexture.getSize().y - 150, 15, UIString::UIString_alignment::right, UIString::UIString_alignment::bottom);
	gameUI->addUIString(0, "Position: (x), (y) relative to [selected object]", 0, uiTexture.getSize().y - 40, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::bottom);
	gameUI->addUIString(0, "Velocity: m/s relative to [selected object]", 0, uiTexture.getSize().y - 20, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::bottom);
	gameUI->addUIString(0, "Acceleration: m/s^2 relative to [selected object]", 0, uiTexture.getSize().y, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::bottom);
	gameUI->addButton(0, "Pause", 5, 5, 15, [&] {gameUI->setActivePage(1); game->setPause(true); });
	gameUI->addPage(); //pause menu
	gameUI->addUIString(1, "Rockets2D", uiTexture.getSize().x / 2, 25, 30, UIString::UIString_alignment::center);
	gameUI->addUIString(1, "Paused", uiTexture.getSize().x / 2, 75, 25, UIString::UIString_alignment::center);
	gameUI->addButton(1, "Resume", 50, 150, 20, [&] {gameUI->setActivePage(0); game->setPause(false); });
	gameUI->addButton(1, "Open Console", 50, 200, 20, [&] {});
	gameUI->addButton(1, "Back to Main Menu", 50, 250, 20, [&] {quitGame(); });
	gameUI->addButton(1, "Quit", 50, 300, 20, [&] {quit(); });
	gameUI->setActive(false);
}

void UIManager::setGame(std::shared_ptr<Game> g) {
	game = g;
}

void UIManager::update() {
	window.clear(sf::Color::Black);
	updateUI();
	pollEvent();
	game->draw(); //draw onto the renderTexture
	window.draw(sf::Sprite(gameTexture.getTexture())); //first the game,

	window.draw(sf::Sprite(uiTexture.getTexture())); //then the ui; this keeps the UI always on top no matter what.
	window.display();
}

sf::RenderTexture* UIManager::getGameTexture() {
	return &gameTexture;
}

sf::RenderTexture* UIManager::getFBTexture() {
	return &freeBodyTexture;
}

bool UIManager::isOpen() {
	return window.isOpen();
}

void UIManager::updateUI() {
	uiTexture.clear(sf::Color::Transparent);
	mainMenu->update();
	gameUI->update();
	uiTexture.display();
}

void UIManager::pollEvent() {
	sf::Event event;
	while (window.pollEvent(event)) {

		switch (event.type) {
		case sf::Event::Closed:
			quit();
			window.close();
			break;

		case sf::Event::MouseWheelScrolled:
			gameView.zoom(1 - event.mouseWheelScroll.delta / 10);
			gameTexture.setView(gameView);
			break;

		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Button::Middle) {
				isPanning = true;
				lastPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			}
			break;

		case sf::Event::MouseButtonReleased :
			if (event.mouseButton.button == sf::Mouse::Button::Middle) {
				isPanning = false;
			
			}
			break;

		case sf::Event::MouseMoved:
			if (isPanning) {
				const sf::Vector2f currentPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
				const sf::Vector2f deltaPos = lastPos - currentPos;
				gameView.move(deltaPos * (gameView.getSize().x / (gameTexture.getSize().x)));
				gameTexture.setView(gameView);
				lastPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			}
			break;
		}
	}
}

void UIManager::play() {
	mainMenu->setActive(false);
	gameUI->setActive(true);
	game->start();
}

void UIManager::controls() {
	mainMenu->setActivePage(2);
}

void UIManager::credits() {
	mainMenu->setActivePage(1);
}

void UIManager::quit() {
	game->stop();
	game->quit();
	window.close();
}

void UIManager::quitGame() {
	game->stop();
	gameUI->setActive(false);
	mainMenu->setActive(true);
}