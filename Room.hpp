#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <ctime>
#include <iostream>

#include "Item.hpp"
#include "Potion.hpp"
#include "Grenade.hpp"
#include "Character.hpp"
#include "NormalGoblin.hpp"
#include "FastGoblin.hpp"
#include "RegenGoblin.hpp"
#include "NormalOrc.hpp"
#include "ArmoredOrc.hpp"
#include "SuperOrc.hpp"
#include "Player.hpp"

class Room
{
private:
	Item* item;
	Character* enemy;
	Player* player;

	Room* northDoor;
	Room* southDoor;
	Room* westDoor;
	Room* eastDoor;

	void spawnEnemy();
	void spawnItem();

public:
	Room();

	void setNorthDoor(Room* north);
	void setSouthDoor(Room* south);
	void setWestDoor(Room* west);
	void setEastDoor(Room* east);
	
	Room* getNorthDoor();
	Room* getSouthDoor();
	Room* getWestDoor();
	Room* getEastDoor();

	void addPlayer(Player* player);
	Player* removePlayer();
	void destroyEnemy();

	Character* getEnemy();
	Item* getItem(bool remove);
};

#endif