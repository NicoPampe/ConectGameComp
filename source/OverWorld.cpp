#include "OverWorld.hpp"

void OverWorld::movePlayer(float dx, float dy) {
	player_ += sf::Vector2f(dx, dy);

	// The player square is 20 units wide.
	if (player_.x > max_bounds_.x - 20) {
		player_.x = max_bounds_.x - 20;
	}
	if (player_.x < min_bounds_.x) {
		player_.x = min_bounds_.x;
	}

	// ... and 25 tall.
	if (player_.y > max_bounds_.y - 25) {
		player_.y = max_bounds_.y - 25;
	}
	if (player_.y < min_bounds_.y) {
		player_.y = min_bounds_.y;
	}

}

sf::Vector2f OverWorld::playerPosition() {
	return player_;
}
