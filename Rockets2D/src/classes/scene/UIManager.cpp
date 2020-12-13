#include "UIManager.h"

UIManager::UIManager() {
	currentView = 0;
	videoSettings.antialiasingLevel = 8;
	window.create(sf::VideoMode(800, 800), "Rockets2D", sf::Style::Close, videoSettings);
	window.setFramerateLimit(300);
	freeBodyTexture.create(150, 150);
	if (!(uiTexture.create(window.getSize().x, window.getSize().y, videoSettings) && gameTexture.create(window.getSize().x, window.getSize().y, videoSettings) && mapTexture.create(window.getSize().x, window.getSize().y, videoSettings) && mapUITexture.create(window.getSize().x, window.getSize().y, videoSettings))) {
		//check for if there is an error creating the gameTexture or the uiTexture
	}
	gameView = gameTexture.getView();
	gameView.setCenter((float)gameTexture.getSize().x / 2, (float)gameTexture.getSize().y / 2);
	gameView.move(-((float)gameTexture.getSize().x / 2), -((float)gameTexture.getSize().y / 2));
	gameTexture.setView(gameView);

	mapView = mapTexture.getView();
	mapView.setCenter((float)mapTexture.getSize().x / 2, (float)mapTexture.getSize().y / 2);
	mapView.move(-((float)mapTexture.getSize().x / 2), -((float)mapTexture.getSize().y / 2));
	mapTexture.setView(mapView);

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

	map = std::make_unique<UIElementManagerGroup>(&mapTexture, &window, &font, &hover, &click, &unClick);
	map->addPage();

	map->setActive(false);

	clock.restart();
	gameView.zoom(1);
	mapView.setSize(gameView.getSize());
	syncFuncs = [&] {gameUI->synchronousUpdate(); mainMenu->synchronousUpdate(); map->synchronousUpdate(); synchronousUpdate(); };
}

UIManager::~UIManager() {
	
}

void UIManager::setGame(std::shared_ptr<Game> g) {
	game = g;
	//slider controls here because the game needs to be set first.
	gameUI->addSlider(0, 100, uiTexture.getSize().y - 140, 250, game->getPlayer()->getThrottlePtr());
	gameUI->addSlider(0, 100, uiTexture.getSize().y - 90, 250, game->getPlayer()->getSteeringPtr());
	gameUI->addFBD(0, uiTexture.getSize().x - 85, uiTexture.getSize().y - 87, 80, game->getPlayer()->getRocketPtr()->getFBPtr(), &canDraw);
	gameUI->addUIString(0, "Throttle:", 10, uiTexture.getSize().y - 140, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::middle);
	gameUI->addUIString(0, "Steering:", 10, uiTexture.getSize().y - 90, 15, UIString::UIString_alignment::left, UIString::UIString_alignment::middle);
	for (std::shared_ptr<Object> obj : *(game->getObjMan()->getObjects())) {
		map->addEmblem(0, &mapUITexture, obj->getPosition().getXPointer(), obj->getPosition().getYPointer(), obj->getTitle(), obj->getDescription());
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
	/*TODO:
	* 1. Obtain the rocket's position and orientaiton.
	* 2. Draw the parts at the position and orientation.
	* 3. Set the center at the position and orientaiton.
	*/

	const Vector2 rocketPosition = game->getPlayer()->getRocketPtr()->getPosition();
	const long double rocketOrientation = game->getPlayer()->getRocketPtr()->getOrientation();
	viewManager(rocketPosition.toDrawSFV());
	game->draw(rocketPosition, rocketOrientation); //draw onto the renderTexture

	if (currentView != 2 || game->getIsPaused()) {
		window.draw(sf::Sprite(gameTexture.getTexture())); //first the game,
		if (isUIVisible) {
			window.draw(sf::Sprite(uiTexture.getTexture())); //then the ui; this keeps the UI always on top no matter what.
		}
	} else {
		window.draw(sf::Sprite(mapTexture.getTexture())); //draw the map when needed
		window.draw(sf::Sprite(mapUITexture.getTexture()));
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
	mapTexture.clear(sf::Color::Transparent);
	mapUITexture.clear(sf::Color::Transparent);
	mainMenu->update();
	gameUI->update();
	map->update();
	mapUITexture.display();
	uiTexture.display();
	mapTexture.display();
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
			switch (currentView) {
			case 0:
				gameView.zoom(1 - event.mouseWheelScroll.delta / 10);
				gameTexture.setView(gameView);
				break;
			case 1:
				gameView.zoom(1 - event.mouseWheelScroll.delta / 10);
				break;
			case 2:
				mapView.zoom(1 - event.mouseWheelScroll.delta / 10);
				mapTexture.setView(mapView);
				break;
			default:
				break;
			}
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
				switch (currentView) {
				case 0:
					break;
				case 1:
					gameView.move(deltaPos * (gameView.getSize().x / (gameTexture.getSize().x)));
					std::cout << gameView.getCenter().y << std::endl;
					gameTexture.setView(gameView);
					break;
				case 2:
					mapView.move(deltaPos * (mapView.getSize().x / (mapTexture.getSize().x)));
					mapTexture.setView(mapView);
					break;
				default:
					break;
				}
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
		translationVector -= sf::Vector2f((float)moveSpeed, 0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		translationVector -= sf::Vector2f(0, (float)moveSpeed);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		translationVector += sf::Vector2f(0, (float)moveSpeed);
	}


	switch (currentView) {
	case 0:
		break;
	case 1:
		gameView.move(translationVector * (gameView.getSize().x / (float)gameTexture.getSize().x) * clock.getElapsedTime().asSeconds());  // if the x component's magnitude is not greater than 0.25, it won't move.  EDIT: this occurs only when the view's center is really far away from the center.  Occurs in the x-axis as well.
		break;
	case 2:
		mapView.move(translationVector * (mapView.getSize().x / mapTexture.getSize().x) * clock.getElapsedTime().asSeconds());
		break;
	default:
		break;
	}
	gameTexture.setView(gameView);
	mapTexture.setView(mapView);
}

void UIManager::play() {
	mainMenu->setActive(false);
	gameUI->setActive(true);
	map->setActive(true);
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
	map->setActive(false);
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

void UIManager::viewManager(const sf::Vector2f& pos) {
	switch (currentView) {
	case 0:
		gameView.setCenter(pos);
		gameTexture.setView(gameView);
		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
}

void UIManager::synchronousUpdate() {
	/*
	switch (currentView) {
	case 0:
		gameView.setCenter((game->getPlayer()->getRocketPtr()->getPosition()).toDrawSFV());
		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
	*/
}