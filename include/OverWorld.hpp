#pragma once

#include <SFML\Graphics.hpp>

// This class is the world that the party can navagate in. The OverWorld will be a gride like layout that the party can move on, from square to square.
// As they navagate the world, they should interacte with grides around them.

class OverWorld {
public:
	void SetBackground();
	void DrawOverWorld(sf::RenderWindow &window);
	
private:
	sf::Texture texture;
	sf::Sprite Background;
};

