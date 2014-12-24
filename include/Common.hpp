#pragma once

// This header is intended to be included just about everywhere.
// Common definitions and reused includes should be put here.

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum class Direction {
	// When in doubt, have it face Down.
	Down,
	Up,
	Left,
	Right
};

#include <vector>
