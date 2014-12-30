#include "Game.hpp"

#include <iostream>
#include <string>

int main() {
	Game game;
	// TODO: This is where we'll load settings files and other IO, before passing the data
	// to Game::setup() to initalize everything.

	if (!game.setup()) {
		// Something went wrong setting up the game. Likely some files didn't load.
		std::cerr << "Game setup failed. Aborting." << std::endl;
		return 1;
	}

	game.start();

	return 0;
}
