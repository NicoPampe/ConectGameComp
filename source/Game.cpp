#include "Game.hpp"
#include "LuaScript.hpp"
#include "OverWorld.hpp"

#include "Common.hpp"

bool Game::setup() {
	const std::string link_filename
		= "resources/images/Zelda_Links_Awakening_SpriteSheet-Correction.psd";

	SpriteManager link_sprites;
	if (!load_link_sprites(link_filename, link_sprites)) {
		return false;
	}

	// Start our player facing south.
	link_sprites.setCurrent("South Base");
	overworld_.setPlayerSprites(std::move(link_sprites));

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

	view_.setCenter(v2i_to_v2f(overworld_.playerPosition()));

	// The test overworld sprite is 1024x1024.
	view_.setSize(1024, 1024);
	view_.zoom(0.3f); // uncomment to zoom out
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
	updateView();
}

void Game::draw() {
	window_.clear(sf::Color::Black);

	// Reference point at the origin.
	sf::CircleShape center;
	const float radius = 10;
	center.setRadius(radius);
	// It's starting position has the top left corner at 0, 0. We want it centered there.
	center.move(-radius, -radius);
	// When textures don't load properly, they're white. Let's make this blue so it stands out.
	center.setFillColor(sf::Color::Blue);
	window_.draw(center);

	overworld_.draw(window_);

	window_.display();
}

// Private methods

void Game::updateView() {
	view_.setCenter(v2i_to_v2f(overworld_.playerPosition()));
	window_.setView(view_);
}

bool Game::load_link_sprites(const std::string& sprite_sheet_filename,
	                                  SpriteManager& link_sprites) {
	sf::Image sprite_sheet;
	if (!sprite_sheet.loadFromFile(sprite_sheet_filename)) {
		return false;
	}

	// All the if-conditions fit in 100 columns now!
	using rect = sf::IntRect;

	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "North Base", rect(66, 6, 14, 16))) {
		// Failed to load, abort!
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "North Walk", rect(80, 6, 14, 16))) {
		return false;
	}

	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "South Base", rect(36, 6, 14, 16))) {
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "South Walk", rect(51, 6, 14, 16))) {
		return false;
	}

	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "West Base", rect(5, 6, 14, 16))) {
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "West Walk", rect(21, 6, 14, 16))) {
		return false;
	}

	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "East Base", rect(109, 6, 14, 16))) {
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "East Walk", rect(94, 6, 14, 16))) {
		return false;
	}

	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "East Hit 1", rect(41, 107, 15, 31))) {
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "East Hit 2", rect(63, 107, 27, 31))) {
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "East Hit 3", rect(94, 107, 30, 31))) {
		return false;
	}

	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "West Hit 1", rect(197, 107, 15, 31))) {
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "West Hit 2", rect(164, 107, 27, 31))) {
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "West Hit 3", rect(130, 107, 30, 31))) {
		return false;
	}

	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "South Hit 1", rect(31, 145, 30, 32))) {
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "South Hit 2", rect(69, 145, 26, 32))) {
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "South Hit 3", rect(102, 145, 15, 32))) {
		return false;
	}

	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "North Hit 1", rect(130, 145, 15, 32))) {
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "North Hit 2", rect(153, 145, 26, 32))) {
		return false;
	}
	if (!link_sprites.addSpriteFromSheet(sprite_sheet, "North Hit 3", rect(183, 145, 30, 32))) {
		return false;
	}

	return true;
}
