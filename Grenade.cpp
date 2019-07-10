#include "Grenade.hpp"

Grenade::Grenade() : Item("Grenade", "Deals 50 damage when thrown")
{
	
}

void Grenade::use(Character* target)
{
	double multiplier = 50.0 / target->getBaseDefenseStat();

	int healthChange = multiplier * (-50);

	std::cout << "You throw the grenade at the " << target->getName() << ". ";
	target->addHealth(healthChange);
}