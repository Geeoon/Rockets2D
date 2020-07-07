#include <iostream>
#include <SFML/Graphics.hpp>
#include <Box2D/box2d.h>
#include "classes/scene/Scene.h"


int main() {
	Scene scene;
	scene.start();
	std::cout << "Hello world.";
	return 0;
}