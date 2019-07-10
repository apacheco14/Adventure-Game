#include "Player.hpp"

Player::Player(std::string name) : Character(name, 500, 50, 50, 50)
{
	
}

bool Player::addItem(Item* item)
{
	if(item)
	{
		this->itemInventory.push_back(item);
		std::cout << item->getName() << " added to inventory. ";
		std::cout << item->getDescription() << std::endl;
		return true;
	}
	else
	{
		std::cout << "No item to add." << std::endl;
		return false;
	}
}

Item* Player::removeItem(std::string name)
{
	bool found = false;
	Item* item;
	for(int x = 0; x < itemInventory.size(); x++)
	{
		if(itemInventory[x]->getName() == name)
		{
			item = itemInventory[x];
			itemInventory.erase(itemInventory.begin()+x);
			found = true;
			break;
		}
	}

	if(found)
	{
		return item;
	}
	else
	{
		std::cout << "Item not found in inventory." << std::endl;
		return NULL;
	}
}

std::string Player::update()
{
	std::string str_userInput;

	std::cout << std::endl << ">> ";
	getline(std::cin, str_userInput);

	return str_userInput;
}

void Player::executeAttack()
{
	this->attack(target, 20);
}

void Player::printInventory()
{
	if(itemInventory.empty())
	{
		std::cout << "Inventory is empty." << std::endl;
	}
	else
	{
		std::cout << "Inventory:" << std::endl;

		for(Item* item : itemInventory)
		{
			std::cout << item->getName() << std::endl;
		}
	}
}