#include "Game.hpp"

#include "Common.hpp"

bool Game::setup() {
	// These dimensions are based off of our test-overworld.
	player_.setSize(sf::Vector2f(20, 25));
	// This is a dark-ish green intended to resemble Link.
	player_.setFillColor(sf::Color(0x00, 0x66, 0x00));

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

	view_.setCenter(0, 0);

	// The test overworld sprite is 1024x1024.
	view_.setSize(1024, 1024);
	updateView();

	while (running_) {
		handleEvents();
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
			auto new_size = sf::Vector2f(event.size.width, event.size.height);
			view_.setSize(new_size);
			updateView();
		}
	}

	const float move_speed = 1;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		player_.move(move_speed, 0);
		view_.move(move_speed, 0);
		updateView();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		player_.move(-move_speed, 0);
		view_.move(-move_speed, 0);
		updateView();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		player_.move(0, move_speed);
		view_.move(0, move_speed);
		updateView();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		player_.move(0, -move_speed);
		view_.move(0, -move_speed);
		updateView();
	}
}

void Game::draw() {
	window_.clear(sf::Color::Black);
	window_.draw(player_);

	// Reference point.
	window_.draw(sf::CircleShape(50, 50));

	window_.display();
}

// Private methods

void Game::updateView() {
	window_.setView(view_);
}
