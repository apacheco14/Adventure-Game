#ifndef POTION_HPP
#define POTION_HPP

#include "Item.hpp"

class Potion : public Item
{
public:
	Potion();
	void use(Character* target);
};

#endif
