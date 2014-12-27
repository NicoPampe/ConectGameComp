#pragma once

#include "OverWorld.hpp"

#include "Common.hpp"

// Manages the game world *as a game*. At this level, we know about graphics and user-input. 
// This is the glue between the user (and SFML) and our model of the world in OverWorld.
class Game {
public:
	Game() {}

	// Load resources and setup the game. If it can't load something, it should make a popup
	//   and abort.
	// No windows are created. After this function finishes, the user should not see the
	//   game running
	bool setup();

	// Start running the game. Open windows, etc. The user should expect their input is handled 
	//   at this point.
	void start();

	// Called after the game ends. Includes things like saving before closing, etc.
	void teardown();

	// Called at least once per game loop to... well... handle events.
	void handleEvents();
	
	void update();

	void draw();

private:
	// Load the sprites from the Links Awakening sprite sheet from sfmlzelda.
	SpriteManager Game::load_link_sprites(const std::string& sprite_sheet_filename);

	// Center view_ on the player and re-attach it to window_.
	// This must be called anytime view_ is moved.
	void updateView();

	// The main window to which everything is drawn.
	sf::RenderWindow window_;

	// This is the 'window' through which we see our virtual world. It's centered on the player.
	sf::View view_;

	// Set to false if and only if the game is over.
	bool running_ = true;

	// The model of our world.
	OverWorld overworld_;
};
