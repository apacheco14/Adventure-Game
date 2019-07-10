#include "Orc.hpp"

Orc::Orc(std::string name, int baseHealthStat, int baseAttackStat,
	int baseDefenseStat, int baseSpeedStat) : Character(name,
	baseHealthStat, baseAttackStat, baseDefenseStat, baseSpeedStat)
{
	
}

std::string Orc::update()
{
	int attack = rand() % 50;		//random number from 0 to 49
	if(attack < this->getBaseSpeedStat())
	{
		this->attack(target, 50 + rand() % 11);
	}

	return "";
}