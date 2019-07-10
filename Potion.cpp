#include "Potion.hpp"

Potion::Potion() : Item("Potion", "Magical potion that is meant to heal you")
{
	
}

void Potion::use(Character* target)
{
	if(rand() % 20 == 0)		// 5% chance Potion does damage
	{
		std::cout << "You drink the potion, but it burns on the way down."
			<< std::endl << "You lose 10 health points. ";
		target->addHealth(50);
	}
	else
	{
		std::cout << "You drink the potion, and it heals 50 health points. ";
		target->addHealth(50);
	}
}