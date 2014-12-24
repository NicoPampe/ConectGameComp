#pragma once

#include "SpriteManager.hpp"
#include "Common.hpp"

class BoardFigure {
public:
	// Inherited destructors *must* be virtual, or else undefined behavior.
	virtual ~BoardFigure();

	virtual void render(sf::RenderWindow& window) const;

protected:
	sf::Vector2i position_;
	Direction facing = Direction::Down;
	SpriteManager sprites_;
};
