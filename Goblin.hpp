#ifndef GOBLIN_HPP
#define GOBLIN_HPP

#include "Character.hpp"

class Goblin : public Character
{
protected:
	bool regenerate;
	Goblin(std::string name, int baseSpeedStat, bool regenerate);

public:
	std::string update();
};

#endif
