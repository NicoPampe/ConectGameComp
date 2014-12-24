#pragma once

#include "SpriteManager.hpp"
#include "Common.hpp"

class BoardFigure {
public:
	// Inherited destructors *must* be virtual, or else undefined behavior.
	virtual ~BoardFigure() {}

	//virtual void draw(sf::RenderWindow& window) const;

	void setPosition(float x, float y) {
		position_ = sf::Vector2f(x, y);
	}
	sf::Vector2f position() const {
		return position_;
	}

protected:
	sf::Vector2f position_;
	Direction facing = Direction::Down;
	SpriteManager sprites_;
};
