#ifndef ORC_HPP
#define ORC_HPP

#include "Character.hpp"

class Orc : public Character
{
protected:
	Orc(std::string name, int baseHealthStat, int baseAttackStat,
		int baseDefenseStat, int baseSpeedStat);

public:
	std::string update();
};

#endif
