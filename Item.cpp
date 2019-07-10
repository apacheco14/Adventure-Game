#include "Item.hpp"

Item::Item(std::string name, std::string description)
{
	this->name = name;
	this->description = description;
}

std::string Item::getName()
{
	return this->name;
}

std::string Item::getDescription()
{
	return this->description;
}