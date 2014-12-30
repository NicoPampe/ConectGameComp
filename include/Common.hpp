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

// If expr is false, return value. Otherwise, carry on. Used to simplify some error handling.
// TODO: Add logging to this macro?
#define return_on_fail(expr, value) if ((expr)) { return (value); }

// Convert from sf::Vector2i to sf::Vector2f with static casts.
inline sf::Vector2f v2i_to_v2f(sf::Vector2i vec) {
	return sf::Vector2f(
		static_cast<float>(vec.x),
		static_cast<float>(vec.y));
}

// It's nice to have std::endl for sf::err().
#include <iostream>