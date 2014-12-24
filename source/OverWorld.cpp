#include "OverWorld.hpp"

#include <iostream> // temp include just to view values

void OverWorld::movePlayer(float dx, float dy) {
	float player_x = player_.position().x + dx;
	float player_y = player_.position().y + dy;

	// Still hard coded.
	auto player_size = sf::Vector2f(20, 25);

	// Bounds check on the map border.
	if (player_x > max_bounds_.x - player_size.x) {
		player_x = max_bounds_.x - player_size.x;
	}
	if (player_x < min_bounds_.x) {
		player_x = min_bounds_.x;
	}

	if (player_y > max_bounds_.y - player_size.y) {
		player_y = max_bounds_.y - player_size.y;
	}
	if (player_y < min_bounds_.y) {
		player_y = min_bounds_.y;
	}

	player_.setPosition(player_x, player_y);

	// TODO: Add generic collision.
	/*
	sf::FloatRect tree_box = tree1_.tree_.getGlobalBounds();
	auto player_box = sf::FloatRect(player_, sf::Vector2f(player_size.x, player_size.y));
	if (tree_box.intersects(player_box)) {
		if (dx > 0) {
			// We're coming from the LEFT, but overshooting.
			//   We need to move the player to the LEFT.
			// [P ---]-- | -- x
			player_x = tree_box.left - player_size.x;
		} else if (dx < 0) {
			// We're coming from the RIGHT, but overshooting.
			//   We need to move the player to the RIGHT.
			// x --| --[P ---]
			player_x = tree_box.left + tree_box.width;
		} else {
			// dx == 0, there's nothing to do.
		}

		if (dy > 0) {
			// Coming from ABOVE, move player UP. (lower y)
			player_y = tree_box.top - player_size.y;
		} else if ( dy < 0) {
			// Coming from BELOW, move player DOWN. (higher y)
			player_y = tree_box.top + tree_box.height;
		} else {
			// dy == 0, there's nothing to do.
		}
	}
	*/
}

sf::Vector2f OverWorld::playerPosition() const {
	auto pos = player_.position();
	return sf::Vector2f(
		static_cast<float>(pos.x),
		static_cast<float>(pos.y)
	);
}
