#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "UIElementManager.h"
#include <vector>

class UIElementManagerGroup
{
public:
	UIElementManagerGroup();

private:
	bool isActive = false;
	std::vector<UIElementManager> managers;
};