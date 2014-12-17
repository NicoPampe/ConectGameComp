#pragma once

#include "OverWorld.hpp"

#include "Common.hpp"

// This class handles the game, such as interactions with the shell. Any keyboard or mouse events are located here.
// Also, rendering functions are taken care of in this class.
class Game {
public:
	Game() {}

	// Load resources and prepare for the game to run. Return false if
	//   something couldn't load.
	bool setup();

	// Start the main gameloop. If bool setup() hasn't been called, abort.
	// This will open the window and begin handling events.
	void start();

	// Called after the game 'ends'. Includes things like saving before
	//   closing, confirming the close, etc.
	void teardown();

	// Process all events in the event queue. This will call into other methods
	//   to deal with
	void handleEvents();


	void update();

	// Draw everything.
	void draw();

private:
	// Re-attaches the view to window_.
	void updateView();

	// Main window to which everything is drawn.
	sf::RenderWindow window_;

	// This is the window through which we see our virtual world. It centers
	//   itself on the player, unless we reach an edge.
	sf::View view_;

	// Eventually, this will be something more general. But this is early
	//   in the development process, so this will be a rectangle
	//   because that's all we need right now.
	sf::RectangleShape player_;

	// The texture to render as the background.
	// TODO: Render parts of a map, which we load ourselves.
	sf::Sprite overworld_background_;

	// TODO: creat a 2d arry or vector to creat multiple trees
	sf::Sprite overworld_trees_;

	// This *must* have the same lifetime as overworld_background_, or we'll
	//   get the "white box problem" and invalid memory issues.
	sf::Texture overworld_background_texture_;
	sf::Texture overworld_tree_texture_;

	// Set to false iff the game is over.
	bool running_ = true;

	// Logical setup for our virtual world.
	OverWorld overworld_;
};
