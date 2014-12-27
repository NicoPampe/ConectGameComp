#pragma once

#include "BoardFigure.hpp"

// Container to better organize data within a map.
struct Tile {
	// Which sprite should be used when rendering this tile. Valid IDs are nonnegative.
	int sprite_id = -1;

	// The rotation of the sprite. Degrees are measured clockwise.
	//   Up    - 0 degrees. No rotation. As-is from the image loaded from disk.
	//   Right - 90 degrees
	//   Down  - 180 degrees
	//   Left  - 270 degrees
	Direction rotation = Direction::Up;

	// Whether or not the tile can be walked over by OverWorldFigures.
	bool walkable = true;
};