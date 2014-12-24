#pragma once

#include "OverWorldFigure.hpp"

class BattleScene {
private:
	// Should these be references?
	OverWorldFigure player_;
	OverWorldFigure enemy_;

	enum class Side {
		Left,
		Right
	};
	Side player_side;
};
