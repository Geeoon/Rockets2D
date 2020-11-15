#include "UIManager.h"

UIManager::UIManager() {
	currentView = 1;
	videoSettings.antialiasingLevel = 8;
	window.create(sf::VideoMode(800, 800), "Rockets2D", sf::Style::Close, videoSettings);
	window.setFramerateLimit(300);
	freeBodyTexture.create(150, 150);
	if (!(uiTexture.create(window.getSize().x, window.getSize().y, videoSettings) && gameTexture.create(window.getSize().x, window.getSize().y, videoSettings))) {
		//check for if there is an error creating the gameTexture or the uiTexture
	}
	gameView = gameTexture.getView();
	gameView.setCenter((float)gameTexture.getSize().x / 2, (float)gameTexture.getSize().y / 2);
	gameView.move(-((float)gameTexture.getSize().x / 2), -((float)gameTexture.getSize().y / 2));
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
	mainMenu->addButton(0, "Settings", 25, 125, 20, [&] {settings(); });
	mainMenu->addButton(0, "Controls", 25, 175, 20, [&] {controls(); });
	mainMenu->addButton(0, "Credits", 25, 225, 20, [&] {credits(); });
	mainMenu->addButton(0, "Quit to Desktop", 25, 275, 20, [&] {quit(); });
	
	mainMenu->addPage(); //credits page 1
	mainMenu->addUIString(1, "Rockets2D", uiTexture.getSize().x / 2, 25, 30, UIString::UIString_alignment::center);
	mainMenu->addUIString(1, "Credits", uiTexture.getSize().x / 2, 60, 20, UIString::UIString_alignment::center);
	mainMenu->addUIString(1, "\
	Created by Geeoon Chung \n\
	UI Sounds provided by Octave http://raisedbeaches.com/octave/ \n\
	Graphics library provided by SFML https://www.sfml-dev.org/ \n\
	", 25, 100, 15);
	mainMenu->addButton(1, "<- Back", 25, 25, 20, [&] {mainMenu->setActivePage(0); });
	
	mainMenu->addPage(); //controls page 2
	mainMenu->addUIString(2, "Rockets2D", uiTexture.getSize().x / 2, 25, 30, UIString::UIString_alignment::center);
	mainMenu->addUIString(2, "Controls", uiTexture.getSize().x / 2, 60, 20, UIString::UIString_alignment::center);
	mainMenu->addUIString(2, "\
	General Controls: \n\
	Pause Game: Escape\n\
	Toggle UI: F6\n\n\
	Map Controls:\n\
	Zoom In: Scroll Wheel Up\n\
	Zoom Out: Scroll Wheel Down\n\
	Pan: Middle Mouse Button\n\
	Move Screen: Directional Keys\n\n\
	Player Controls:\n\
	Throttle Up: W\n\
	Throttle Down: D\n\
	Roll Left: A\n\
	Roll Right: D\n\
	", 25, 100, 15);
	mainMenu->addButton(2, "<- Back", 25, 25, 20, [&] {mainMenu->setActivePage(0); });

	mainMenu->addPage(); //settings page 3
	mainMenu->addUIString(3, "Rockets2D", uiTexture.getSize().x / 2, 25, 30, UIString::UIString_alignment::center);
	mainMenu->addUIString(3, "Settings", uiTexture.getSize().x / 2, 60, 20, UIString::UIString_alignment::center);
	//mainMenu->addButton(3, "<- Back", 25, 25, 20, [&] {mainMenu->setActivePage(0); });
	mainMenu->addButton(3, "Save Settings", 25, uiTexture.getSize().y - 55, 20, [&] {saveUserConfigs(); mainMenu->setActivePage(0); });
	mainMenu->addUIString(3, "Anti-Aliasing Level: ", 25, 125, 14);
	mainMenu->addRadioList(3, 195, 125, 14, new std::string[4]{ "Off", "MSAA 2x", "MSAA 4x", "MSAA 8x" }, 4, 0); //possible memory leak
	mainMenu->addUIString(3, "FreeBody Diagram Orientation: ", 25, 150, 14);//relative to sceen, relative to object, relative to self
	mainMenu->addRadioList(3, 268, 150, 14, new std::string[3]{ "Relative to Screen", "Relative to Object", "Relative to Player" }, 3, 0); //possible memory leak
	
	mainMenu->setActive(true);

	gameUI = std::make_unique<UIElementManagerGroup>(&uiTexture, &window, &font, &hover, &click, &unClick);
	gameUI->addPage(); //standard non-pause game
	gameUI->addUIString(0, "Free Body Diagram", uiTexture.getSize().x - 10, uiTexture.getSize().y - 160, 15, UIString::UIString_alignment::right, UIString::UIString_alignment::bottom);
	gameUI->addUIString(0, "Position: (x), (y) relative to [selected object]", 0, uiTexture.getSize().y - 40, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::bottom);
	gameUI->addUIString(0, "Velocity: m/s relative to [selected object]", 0, uiTexture.getSize().y - 20, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::bottom);
	gameUI->addUIString(0, "Acceleration: m/s^2 relative to [selected object]", 0, uiTexture.getSize().y, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::bottom);
	gameUI->addButton(0, "Pause", 5, 5, 15, [&] {gameUI->setActivePage(1); game->setPause(true); });
	gameUI->addBackground(0, uiTexture.getSize().x / 2, uiTexture.getSize().x - 80, uiTexture.getSize().x + 20, 200);

	gameUI->addPage(); //pause menu
	gameUI->addUIString(1, "Rockets2D", uiTexture.getSize().x / 2, 25, 30, UIString::UIString_alignment::center);
	gameUI->addUIString(1, "Paused", uiTexture.getSize().x / 2, 75, 25, UIString::UIString_alignment::center);
	gameUI->addButton(1, "Resume", 50, 150, 20, [&] {gameUI->setActivePage(0); game->setPause(false); });
	gameUI->addButton(1, "Open Console", 50, 200, 20, [&] {});
	gameUI->addButton(1, "Quit to Main Menu", 50, 250, 20, [&] {quitGame(); });
	gameUI->addButton(1, "Quit to Desktop", 50, 300, 20, [&] {quit(); });
	gameUI->setActive(false);

	clock.restart();
	gameView.zoom(1);
	gameView.setSize(2.07544 * pow(10, 10), 2.07544 * pow(10, 10));
	syncFuncs = [&] {gameUI->synchronousUpdate(); mainMenu->synchronousUpdate(); synchronousUpdate(); };
}

void UIManager::setGame(std::shared_ptr<Game> g) {
	game = g;
	//slider controls here because the game needs to be set first.
	gameUI->addSlider(0, 100, uiTexture.getSize().y - 140, 250, game->getPlayer()->getThrottlePtr());
	gameUI->addSlider(0, 100, uiTexture.getSize().y - 90, 250, game->getPlayer()->getSteeringPtr());
	gameUI->addFBD(0, uiTexture.getSize().x - 85, uiTexture.getSize().y - 87, 80, game->getPlayer()->getRocketPtr()->getFBPtr(), &canDraw);
	gameUI->addUIString(0, "Throttle:", 10, uiTexture.getSize().y - 140, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::middle);
	gameUI->addUIString(0, "Steering:", 10, uiTexture.getSize().y - 90, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::middle);
	//gameUI->addEmblem(0, 300, 300, "test", "test");
	//map->addUIString(0, "TEST STRING", 10, uiTexture.getSize().y - 140, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::middle);
	for (std::shared_ptr<Object> obj : *(game->getObjMan()->getObjects())) {
		gameUI->addEmblem(0, 300, 300, "Test", "description");
		std::cout << "test";
	}
}

const std::function<void()>& UIManager::getSyncFuncs() {
	return syncFuncs;
}

void UIManager::update() {
	clock.restart();
	window.clear(sf::Color::Black);
	if (isUIVisible) {
		updateUI();
	}
	canDraw = true;
	pollEvent();
	manageControls();
	game->draw(); //draw onto the renderTexture
	viewManager();
	if (currentView != 2) {
		window.draw(sf::Sprite(gameTexture.getTexture())); //first the game,
		if (isUIVisible) {
			window.draw(sf::Sprite(uiTexture.getTexture())); //then the ui; this keeps the UI always on top no matter what.
		}
	} else {
		//window.draw(sf::Sprite(mapTexture.getTexture())); //draw the map when needed
	}
	canDraw = false;
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
		game->getPlayer()->manageEvents(event);
		switch (event.type) {
		case sf::Event::Closed:
			quit();
			break;

		case sf::Event::MouseWheelScrolled:
			gameView.zoom(1 - event.mouseWheelScroll.delta / 10);
			gameTexture.setView(gameView);
			break;

		case sf::Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Button::Middle) {
				isPanning = true;
			}
			lastPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
			break;

		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Button::Middle) {
				isPanning = false;
			}
			break;
		
		case sf::Event::KeyPressed:
			switch (event.key.code) {
			case sf::Keyboard::F6:
				isUIVisible = !isUIVisible;
				break;
			case sf::Keyboard::Escape:
				gameUI->setActivePage(1);
				game->setPause(true);
				break;
			case sf::Keyboard::Space:
				swapView();
				break;
			}
			break;
		case sf::Event::MouseMoved:
			if (isPanning && currentView != 0) {
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

void UIManager::manageControls() {
	game->getPlayer()->manageControls();
	sf::Vector2f translationVector(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		translationVector += sf::Vector2f((float)moveSpeed, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		translationVector += sf::Vector2f(-(float)moveSpeed, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		translationVector += sf::Vector2f(0, -(float)moveSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		translationVector += sf::Vector2f(0, (float)moveSpeed);
	}

	gameView.move(translationVector * (gameView.getSize().x / (gameTexture.getSize().x)) * clock.getElapsedTime().asSeconds());
	gameTexture.setView(gameView);
}

void UIManager::play() {
	mainMenu->setActive(false);
	gameUI->setActive(true);
	game->start();
}

void UIManager::controls() {
	mainMenu->setActivePage(2);
}

void UIManager::settings() {
	mainMenu->setActivePage(3);
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

void UIManager::saveUserConfigs() {
	
}

void UIManager::swapView() {
	currentView++;
	lastPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (currentView > 2) {
		currentView = 0;
	}
}

void UIManager::viewManager() {
	if (currentView == 0) { //gameView; center
		gameView.setCenter((game->getPlayer()->getRocketPtr()->getPosition()).toDrawSFV());
	} else if (currentView == 1) { //gameView; player controlled
		
	} else if (currentView == 2) {//mapView

	}
}

void UIManager::synchronousUpdate() {
	
}