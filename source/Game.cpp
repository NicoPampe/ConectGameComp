#include "Game.hpp"
#include "OverWorld.hpp"
#include "Lua.hpp"

#include "Common.hpp"

bool Game::setup() {
	// These dimensions are based off of our test-overworld.
	player_.setSize(sf::Vector2f(20, 25));
	// This is a dark-ish green intended to resemble Link.
	player_.setFillColor(sf::Color(0x00, 0x66, 0x00));

	if (!overworld_background_texture_.loadFromFile("resources/TestOverworld.png")) {
		// Something went wrong loading the texture.
		return false;
	}
	overworld_background_.setTexture(overworld_background_texture_);

	Lua map("resources/OverWorldMap.lua");
	//map.load();
	

	sf::Vector2f temp;
	temp.x = 30;
	temp.y = 30;
	overworld_.tree1_.set_tree_position_(temp);
	overworld_.tree1_.set_texture_();

	//if (!overworld_tree_texture_.loadFromFile("Tree1.png")) {
	//	// Something went wrong loading the texture.
	//	return false;
	//}
	//overworld_trees_.setTexture(overworld_tree_texture_);
	//Tree tree_temp_;
	//tree_temp_;

	return true;
}

void Game::start() {
	// Setup the window and attach the view.
	window_.create(
		// The test overworld sprite is 1024x1024.
		sf::VideoMode(1024, 1024),
		"CS Connect Game!",
		sf::Style::Default
		);

	view_.setCenter(overworld_.playerPosition());

	// The test overworld sprite is 1024x1024.
	view_.setSize(1024, 1024);
	view_.zoom(0.3); // uncomment to zoom in
	updateView();

	while (running_) {
		handleEvents();
		update();
		draw();
	}
}

void Game::handleEvents() {
	sf::Event event;

	while (window_.pollEvent(event)) {
		if (event.type == sf::Event::Closed
			|| sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			running_ = false;
			window_.close();
		}
		if (event.key.code == sf::Keyboard::Space
			&& event.type == sf::Event::KeyPressed) {
			player_.rotate(15);
		}
		if (event.type == sf::Event::Resized) {
			auto new_size = sf::Vector2f(
				static_cast<float>(event.size.width),
				static_cast<float>(event.size.height));
			view_.setSize(new_size);
			view_.zoom(0.3);
		}
	}

	const float move_speed = 0.4f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		overworld_.movePlayer(move_speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		overworld_.movePlayer(-move_speed, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		overworld_.movePlayer(0, move_speed);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		overworld_.movePlayer(0, -move_speed);
	}
}

void Game::update() {
	player_.setPosition(overworld_.playerPosition());
	updateView();
}

void Game::draw() {
	window_.clear(sf::Color::Black);

	// Draw the background first, so everthing is drawn ontop of it.
	window_.draw(overworld_background_);
	
	// Draw the objects ontop of the background
	window_.draw(overworld_.tree1_.tree_);
	
	// Reference point.
	sf::CircleShape center;
	center.setRadius(25);
	center.move(-25, -25);
	window_.draw(center);

	// Draw the player last, so that they are on top.
	window_.draw(player_);
	window_.display();
}

// Private methods

void Game::updateView() {
	view_.setCenter(overworld_.playerPosition());
	window_.setView(view_);
}
