#include "OverWorld.hpp"

#include <iostream> // temp include just to view values

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

	// running into objects
	std::cout << player_.x << " " <<player_.y << " : "  << tree1_.get_tree_position_x_() << " " << tree1_.get_tree_position_y_() << std::endl;
	// Max bound 59 min bound 80
	sf::FloatRect bounding_box = tree1_.tree_.getGlobalBounds();
	if (bounding_box.contains(player_)) {
		std::cout << "collision!   ";
		if (player_.x < tree1_.get_tree_position_x_() + 59)
			std::cout << "from the x";

		int delt_x = player_.x - tree1_.get_tree_position_x_();
		int delt_y = player_.y - tree1_.get_tree_position_y_();
		if (delt_x > delt_y)
			player_.x = tree1_.get_tree_position_x_() + 59;
		else if (delt_x < delt_y)
			player_.y = tree1_.get_tree_position_y_() + 80;
		std::cout << std::endl << delt_x << "  " << delt_y << std::endl;
		
		/*if (player_.x < tree1_.get_tree_position_x_() + 59)
			player_.x = tree1_.get_tree_position_x_() + 59;
		if (player_.y < tree1_.get_tree_position_y_() + 80)
			player_.y = tree1_.get_tree_position_y_() + 80;*/
	}
	
	// TODO: fix the code to use the max and min bounds. should not be using the get_x and get_y. 
	/*if (player_.x < tree1_.max_bounds.x) {
		player_.x = tree1_.max_bounds.x;
	}*/
}

sf::Vector2f OverWorld::playerPosition() {
	return player_;
}
