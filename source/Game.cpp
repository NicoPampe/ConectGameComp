#include "Game.hpp"
#include "LuaScript.hpp"
#include "OverWorld.hpp"

#include "Common.hpp"

bool Game::setup() {

	SpriteManager link_sprites 
		= load_link_sprites("images/Zelda_Links_Awakening_SpriteSheet-Correction.psd");

	// These dimensions are based off of our test-overworld.
	player_.setSize(sf::Vector2f(20, 25));
	// This is a dark-ish green intended to resemble Link.
	player_.setFillColor(sf::Color(0x00, 0x66, 0x00));

	if (!overworld_background_texture_.loadFromFile("resources/TestOverworld.png")) {
		// Something went wrong loading the texture.
		return false;
	}
	overworld_background_.setTexture(overworld_background_texture_);

	return true;
}

void Game::start() {
	// Setup the window and attach the view.
	window_.create(
		// The test overworld sprite is 1024x1024.
		// TODO: Make this load settings from a file. Do that in setup().
		sf::VideoMode(1024, 1024),
		"CS Connect Game!",
		sf::Style::Default
		);

	view_.setCenter(overworld_.playerPosition());

	// The test overworld sprite is 1024x1024.
	view_.setSize(1024, 1024);
	view_.zoom(0.3f); // uncomment to zoom in
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
			view_.zoom(0.3f);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		overworld_.movePlayer(Direction::Right);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		overworld_.movePlayer(Direction::Left);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		overworld_.movePlayer(Direction::Down);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		overworld_.movePlayer(Direction::Up);
	}
}

void Game::update() {
	player_.setPosition(overworld_.playerPosition());
	updateView();
}

void Game::draw() {
	window_.clear(sf::Color::Black);

	overworld_.draw(window_);

	// Reference point at the origin.
	sf::CircleShape center;
	const float radius = 10;
	center.setRadius(radius);
	// It's starting position has the top left corner at 0, 0. We want it centered there.
	center.move(-radius, -radius);
	window_.draw(center);

	window_.display();
}

// Private methods

void Game::updateView() {
	view_.setCenter(overworld_.playerPosition());
	window_.setView(view_);
}

SpriteManager Game::load_link_sprites(const std::string& sprite_sheet_filename) {
	sf::Image sprite_sheet;
	sprite_sheet.loadFromFile(sprite_sheet_filename);

	SpriteManager link_sprites;
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "North Base Texture", sf::IntRect(66, 6, 14, 16));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "North Walk Texture", sf::IntRect(80, 6, 14, 16));

	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "South Base Texture", sf::IntRect(36, 6, 14, 16));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "South Walk Texture", sf::IntRect(51, 6, 14, 16));

	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "West Base Texture", sf::IntRect(5, 6, 14, 16));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "West Walk Texture", sf::IntRect(21, 6, 14, 16));

	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "East Base Texture", sf::IntRect(109, 6, 14, 16));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "East Walk Texture", sf::IntRect(94, 6, 14, 16));

	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "East Hit Texture 1", sf::IntRect(41, 107, 15, 31));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "East Hit Texture 2", sf::IntRect(63, 107, 27, 31));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "East Hit Texture 3", sf::IntRect(94, 107, 30, 31));

	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "West Hit Texture 1", sf::IntRect(197, 107, 15, 31));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "West Hit Texture 2", sf::IntRect(164, 107, 27, 31));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "West Hit Texture 3", sf::IntRect(130, 107, 30, 31));

	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "South Hit Texture 1", sf::IntRect(31, 145, 30, 32));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "South Hit Texture 2", sf::IntRect(69, 145, 26, 32));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "South Hit Texture 3", sf::IntRect(102, 145, 15, 32));

	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "North Hit Texture 1", sf::IntRect(130, 145, 15, 32));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "North Hit Texture 2", sf::IntRect(153, 145, 26, 32));
	link_sprites.add_sprite_from_sheet(
		sprite_sheet, "North Hit Texture 3", sf::IntRect(183, 145, 30, 32));
}
