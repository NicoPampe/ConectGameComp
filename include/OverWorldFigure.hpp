#pragma once

#include "BoardFigure.hpp"
#include "PartyFigure.hpp"
#include "Common.hpp"

class OverWorldFigure : public BoardFigure {
public:
	void replaceParty(std::vector<PartyFigure>& party);

private:
	std::vector<PartyFigure> party_;
};
