#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <functional>
#include "SpaceObject.h"
#include "Player.h"
#include "ObjectManager.h"
#include "Rocket/RocketPartsManager.h"
#include "Rocket/RocketParts/Engines/Engine.h"
#include "Rocket/Rocket.h"

class Game
{
public:
	Game(sf::RenderTexture* t);
	void start();
	void stop();
	void quit();
	void update();
	void setPause(bool p);
	bool getIsPaused();
	void draw();
	void draw(const Vector2& pos, long double ori);
	void addToSync(const std::function<void()>& f);
	Player* getPlayer();
	ObjectManager* getObjMan();
private:
	void syncronousUpdate(); //for updating things syncronously with the game thread.
	bool hasStarted = false;
	bool isPaused = false;
	bool isQuit = false;
	//sf::Clock gameClock;
	std::vector<std::function<void()>> syncFuncs;
	std::unique_ptr<SpaceObject> testObject;
	std::unique_ptr<SpaceObject> testObject2;
	std::unique_ptr<Player> player;
	std::unique_ptr<Rocket> rocket;
	std::shared_ptr<Object> focus;
	sf::RenderTexture* texture = nullptr;
	sf::RenderTexture* fbTexture = nullptr;
	std::unique_ptr<ObjectManager> objMan;
};

