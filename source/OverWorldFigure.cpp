#include "OverWorldFigure.hpp"

void OverWorldFigure::move(Direction direction, int paces) {
	switch (direction) {
	case Direction::Up: {
		sprites_.setCurrent("North Base");
		position_ += sf::Vector2i(0, -paces);
		break;
	}

	case Direction::Down: {
		sprites_.setCurrent("South Base");
		position_ += sf::Vector2i(0, paces);
		break;
	}

	case Direction::Left: {
		sprites_.setCurrent("West Base");
		position_ += sf::Vector2i(-paces, 0);
		break;
	}

	case Direction::Right: {
		sprites_.setCurrent("East Base");
		position_ += sf::Vector2i(paces, 0);
		break;
	}


	}
}
