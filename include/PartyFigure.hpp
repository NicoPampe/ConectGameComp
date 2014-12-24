#pragma once

#include "BoardFigure.hpp"

class PartyFigure : public BoardFigure {
private:
	// Whichever stats we'll eventually care about go here. For now, they're just fillers.
	// We might, instead, inherit from PartyFigure to create each type of party member.
	double hp_;
	double attack_;
	double defense_;
};
