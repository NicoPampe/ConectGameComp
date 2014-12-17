#pragma once

#include "OverWorldObjects.hpp"

#include "Common.hpp"

// This class is the world that the party can navagate in. The OverWorld will be a gride like layout that the party can move on, from square to square.
// As they navagate the world, they should interacte with grides around them.

class OverWorld {
public:
	// Move the player by (dx, dy).
	void movePlayer(float dx, float dy);

	// Return the location of the player in the overworld.
	sf::Vector2f playerPosition();

	void setBounds(sf::Vector2f min, sf::Vector2f max);
	sf::Vector2f minBounds();
	sf::Vector2f maxBounds();

	// TODO: create a 2D vector or arry to put multiple trees in the overworld
	Tree tree1_;

private:
	// TODO: Have some sort of player object.
	
	// TODO: load objects in the overworld
	
	// Start the player in the middle of the board.
	sf::Vector2f player_ = sf::Vector2f(512, 512);

	sf::Vector2f min_bounds_ = sf::Vector2f(0, 0);
	sf::Vector2f max_bounds_ = sf::Vector2f(1024, 1024);

};

