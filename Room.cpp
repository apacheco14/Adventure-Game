#include "Room.hpp"

Room::Room()
{
	spawnEnemy();
	spawnItem();

	this->northDoor = NULL;
	this->southDoor = NULL;
	this->westDoor = NULL;
	this->eastDoor = NULL;
	player = NULL;
}

void Room::spawnEnemy()
{
	int number = rand() % 20 + 1;				// 1 to 20

	if(number >= 1 && number <= 6)
	{
		enemy = new NormalGoblin("Goblin");		// 6/20 = 30% chance
	}
	else if(number >= 7 && number <= 9)
	{
		enemy = new FastGoblin("Fast Goblin");	// 3/20 = 15% chance
	}
	else if(number == 10)
	{
		enemy = new RegenGoblin("Regenerating Goblin");	// 1/20 = 5% chance
	}
	else if(number >= 11 && number <= 16)
	{
		enemy = new NormalOrc("Orc");			// 6/20 = 30% chance
	}
	else if(number >= 17 && number <= 19)
	{
		enemy = new ArmoredOrc("Armored Orc");	// 3/20 = 15% chance
	}
	else if(number == 20)
	{
		enemy = new SuperOrc("Super Orc");		// 1/20 = 5% chance
	}
}

void Room::spawnItem()
{
	int number = rand() % 20 + 1;				// 1 to 20

	if(number >= 1 && number <= 20)
	{
		item = new Potion();					// 5/20 = 25% chance
	}
	else if(number >= 6 && number <= 10)
	{
		item = new Grenade();					// 5/20 = 25% chance
	}
	// else no item								// 10/20 = 50% chance
}

void Room::setNorthDoor(Room* north)
{
	this->northDoor = north;
}

void Room::setSouthDoor(Room* south)
{
	this->southDoor = south;
}

void Room::setWestDoor(Room* west)
{
	this->westDoor = west;	
}

void Room::setEastDoor(Room* east)
{
	this->eastDoor = east;
}

Room* Room::getNorthDoor()
{
	return this->northDoor;
}

Room* Room::getSouthDoor()
{
	return this->southDoor;
}

Room* Room::getWestDoor()
{
	return this->westDoor;
}

Room* Room::getEastDoor()
{
	return this->eastDoor;
}

void Room::addPlayer(Player* player)
{
	this->player = player;
	std::cout << "You enter a room.";

	if(enemy)
	{
		int number = rand() % 10;
		switch(number)
		{
			case 0:
				std::cout << " There is an angry";
				break;
			case 1:
				std::cout << " There is a scary";
				break;
			case 2:
				std::cout << " There is a threatening";
				break;
			case 3:
				std::cout << " There is a raging";
				break;
			case 4:
				std::cout << " There is an evil";
				break;
			default:
			{
				std::cout << " There is a";
				if(enemy->getName()[0] == 'A'
					|| enemy->getName()[0] == 'E'
					|| enemy->getName()[0] == 'I'
					|| enemy->getName()[0] == 'O'
					|| enemy->getName()[0] == 'U')
				{
					std::cout << "n";
				}
			}
		}

		std::cout << " " << enemy->getName() << ".";
	}

	std::cout << std::endl;
}

Player* Room::removePlayer()
{
	Player* tempPlayer = player;
	player = NULL;
	return tempPlayer;
}

Character* Room::getEnemy()
{
	return this->enemy;
}

void Room::destroyEnemy()
{
	this->enemy = NULL;
}

Item* Room::getItem(bool remove)
{
	if(remove)
	{
		Item* tempItem = this->item;
		this->item = NULL;
		return tempItem;
	}
	else
	{
		return this->item;
	}
}