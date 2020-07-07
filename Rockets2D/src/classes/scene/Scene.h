#pragma once
#include "UIManager.h"

class Scene
{
public:
	Scene();
	void start();

private:
	bool isQuit = false;
	UIManager ui;
};