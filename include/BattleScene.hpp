#pragma once

#include "OverWorldFigure.hpp"

// The class which manages the combat. When active, we pause the OverWorld and begin rendering
//   ontop of it. This is the meat and bones of the game. 
class BattleScene {
private:
	OverWorldFigure player_;
	OverWorldFigure enemy_;

	enum class Side {
		Left,
		Right
	};
	Side player_side_;
};
