#pragma once

#include "BattleScene.hpp"
#include "OverWorldFigure.hpp"
#include "Tile.hpp"
#include "Common.hpp"

// This class is the world that the party can navigate in. The OverWorld will be a grid like layout
//   that the party can move on, from square to square. As they navigate the world, they should
//   interact with grid-squares around them.

class OverWorld {
public:
	// Move the player by (dx, dy).
	void movePlayer(float dx, float dy);

	// Return the location of the player in the overworld.
	sf::Vector2f playerPosition() const;

	void setBounds(sf::Vector2f min, sf::Vector2f max);
	sf::Vector2f minBounds() const;
	sf::Vector2f maxBounds() const;

	void render(sf::RenderWindow& window) const;

private:
	// We special-case the player.
	OverWorldFigure player_;
	// All other enemy-player things go in here.
	std::vector<OverWorldFigure> enemies_;
	std::vector<Tile> tiles_;

	// When we enter a battle, another mini-screen shows up. There is only one at a time,
	//   but it's not always active. Thus,
	BattleScene scene_;
	bool battle_scene_is_active_ = false;

	sf::Vector2f min_bounds_ = sf::Vector2f(0, 0);
	sf::Vector2f max_bounds_ = sf::Vector2f(1024, 1024);
};

