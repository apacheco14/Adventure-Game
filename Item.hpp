#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "Character.hpp"

class Item
{
protected:
	std::string name;
	std::string description;

public:
	Item(std::string name, std::string description);
	std::string getName();
	std::string getDescription();
	virtual void use(Character* target) = 0;
};

#endif
