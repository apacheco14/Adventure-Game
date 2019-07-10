#ifndef GRENADE_HPP
#define GRENADE_HPP

#include "Item.hpp"

class Grenade : public Item
{
public:
	Grenade();
	void use(Character* target);
};

#endif
