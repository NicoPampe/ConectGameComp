#pragma once

#include "SpriteManager.hpp"
#include "Common.hpp"

// The parent class for anything which needs to move about a grid board.
class BoardFigure {
public:
	// Inherited destructors *must* be virtual, or else undefined behavior.

	virtual ~BoardFigure() {}

	virtual void draw(sf::RenderWindow& window) const {
		sf::Sprite sprite = sprites_.getCurrent();
		sprite.setPosition(v2i_to_v2f(position_));
		window.draw(sprite);
	}

	void setPosition(int x, int y) {
		position_ = sf::Vector2i(x, y);
	}

	sf::Vector2i position() const {
		return position_;
	}

	void setSprites(SpriteManager&& sprites) {
		sprites_ = std::move(sprites);
	}

protected:
	sf::Vector2i position_;
	Direction facing = Direction::Down;
	SpriteManager sprites_;
};
