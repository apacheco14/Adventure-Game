#include "Goblin.hpp"

Goblin::Goblin(std::string name, int baseSpeedStat, bool regenerate) : Character(name, 100, 25, 25, baseSpeedStat)
{
	this->regenerate = regenerate;
}

std::string Goblin::update()
{
	if(this->regenerate)
	{
		addHealth(20);
	}

	int attack = rand() % 50;		//random number from 0 to 49
	if(attack < this->getBaseSpeedStat())
	{
		this->attack(target, 50 + rand() % 11);
	}

	return "";
}