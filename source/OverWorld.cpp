#include "OverWorld.hpp"


#include <iostream>

void OverWorld::SetBackground() {
	//texture.loadFromFile("TestOverWorld.png");
	if (!texture.loadFromFile("TestOverWorld.png"))
		std::cout << "ERROR OPENING FILE";
	Background.setTexture(texture);	
}

void OverWorld::DrawOverWorld(sf::RenderWindow &window) {
	sf::Vector2u windowScale = window.getSize();
	//sf::Vector2f size = window.getSize();
	//Background.setScale(windowScale.x, windowScale.y);
	//Background.setScale((float)1 / ((float)1000 / windowScale.x), (float)1 / ((float)1000 / windowScale.y));
	//Background.setScale(.5, .5);
	sf::Vector2f sizeB = Background.getScale();
	std::cout << sizeB.x << " " << sizeB.y << std::endl;
	window.draw(Background);
}