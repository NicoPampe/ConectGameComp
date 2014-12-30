#include "OverWorld.hpp"

void OverWorld::movePlayer(Direction direction) {
	// I'm lazy, nothing more.
	auto x = player_.position().x;
	auto y = player_.position().y;
	
	// Don't let the player move until we know it's open.
	int paces = 0;
	const int map_size = 300;

	// Collision with an imaginary, hard coded border.
	// Eventually, we'll have this information in the map script.
	if (  ((direction == Direction::Down  && y < max_bounds_.y)
		|| (direction == Direction::Up    && y > min_bounds_.y)
		|| (direction == Direction::Left  && x > min_bounds_.x)
		|| (direction == Direction::Right && x < max_bounds_.x))) {
		paces = 1;
	}
	player_.move(direction, paces);
}

void OverWorld::draw(sf::RenderWindow& window) const {
	player_.draw(window);
}