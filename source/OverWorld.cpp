#include "OverWorld.hpp"

#include <iostream> // temp include just to view values

void OverWorld::movePlayer(float dx, float dy) {
	player_ += sf::Vector2f(dx, dy);
	auto player_size = sf::Vector2f(20, 25);

	if (player_.x > max_bounds_.x - player_size.x) {
		player_.x = max_bounds_.x - player_size.x;
	}
	if (player_.x < min_bounds_.x) {
		player_.x = min_bounds_.x;
	}

	if (player_.y > max_bounds_.y - player_size.y) {
		player_.y = max_bounds_.y - player_size.y;
	}
	if (player_.y < min_bounds_.y) {
		player_.y = min_bounds_.y;
	}

	sf::FloatRect tree_box = tree1_.tree_.getGlobalBounds();
	auto player_box = sf::FloatRect(player_, sf::Vector2f(player_size.x, player_size.y));
	if (tree_box.intersects(player_box)) {
		if (dx > 0) {
			// We're coming from the LEFT, but overshooting.
			//   We need to move the player to the LEFT.
			// [P ---]-- | -- x
			player_.x = tree_box.left - player_size.x;
		} else if (dx < 0) {
			// We're coming from the RIGHT, but overshooting.
			//   We need to move the player to the RIGHT.
			// x --| --[P ---]
			player_.x = tree_box.left + tree_box.width;
		} else {
			// dx == 0, there's nothing to do.
		}

		if (dy > 0) {
			// Coming from ABOVE, move player UP. (lower y)
			player_.y = tree_box.top - player_size.y;
		} else if ( dy < 0) {
			// Coming from BELOW, move player DOWN. (higher y)
			player_.y = tree_box.top + tree_box.height;
		} else {
			// dy == 0, there's nothing to do.
		}
	}
}

sf::Vector2f OverWorld::playerPosition() {
	return player_;
}
