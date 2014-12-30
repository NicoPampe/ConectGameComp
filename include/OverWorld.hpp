#pragma once

#include "BattleScene.hpp"
#include "OverWorldFigure.hpp"
#include "Tile.hpp"
#include "Common.hpp"

// This class is the world that the party can navigate in. The OverWorld is a grid,
//   with OverWorldFigures moving along integral cooridnates.
class OverWorld {
public:
	OverWorld() {}

	// Move the player along gridlines.
	void movePlayer(Direction direction) {}

	// The location of the player in the grid-world.
	sf::Vector2i playerPosition() const {
		return player_.position();
	}

	// Draw the entire overworld, its OverWorldFigures, etc. Everything.
	void draw(sf::RenderWindow& window) const;

	void setPlayerSprites(SpriteManager&& sprites) {
		player_.setSprites(std::move(sprites));
	}

private:
	OverWorldFigure player_;

	// Anything which moves in the OverWorld, but isn't player-controlled.
	std::vector<OverWorldFigure> enemies_;
	
	// Static background data. Where OverWorldFigures are allowed to walk, and how the tiles should render.
	std::vector<Tile> map_;

	// Since the map is stored in 1D, we keep track of the dimensions here.

	// Size of the map, measured in tiles, along the x-axis.
	size_t map_x_ = 0;
	// Size of the map, measured in tiles, along the x-axis.
	size_t map_y_ = 0;

	// The data relevant to the battle taking place, if any.
	BattleScene scene_;

	// Whether or not a battle is taking place.
	bool battle_scene_is_active_ = false;

	// Minimum x and y values allowed by anything (Tiles, OverWorldFigures) in the OverWorld.
	sf::Vector2f min_bounds_ = sf::Vector2f(0, 0);

	// Maximum x and y values allowed by anything (Tiles, OverWorldFigures) in the OverWorld.
	sf::Vector2f max_bounds_ = sf::Vector2f(1024, 1024);
};

