#pragma once
#include <thread>
#include "UIManager.h"
#include "../game/Game.h"

class Scene
{
public:
	Scene();
	~Scene();
	void start();

private:
	UIManager ui;
	std::shared_ptr<Game> game;
};