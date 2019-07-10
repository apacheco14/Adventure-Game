#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include "Character.hpp"
#include "Item.hpp"

class Player : public Character
{
private:
	std::vector<Item*> itemInventory;

public:
	Player(std::string name);
	bool addItem(Item* item);
	Item* removeItem(std::string name);
	std::string update();
	void executeAttack();
	void printInventory();
};

#endif