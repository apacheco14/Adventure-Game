#include "Dungeon.hpp"

Dungeon::Dungeon(Player* player)
{
	this->player = player;

	for(int r = 0; r < 13; r++)
	{
		rooms.push_back(new Room());
	}

	/*
		
		12
		 |
		10   7---6---5
		 |	 |		 |
		 9---8		 4
		 |			 |
		11		 3---1---2
					 |
					 0

	*/

	joinRoomsNorthSouth(rooms[1], rooms[0]);
	joinRoomsEastWest(rooms[2], rooms[1]);
	joinRoomsEastWest(rooms[1], rooms[3]);
	joinRoomsNorthSouth(rooms[4], rooms[1]);
	joinRoomsNorthSouth(rooms[5], rooms[4]);
	joinRoomsEastWest(rooms[5], rooms[6]);
	joinRoomsEastWest(rooms[6], rooms[7]);
	joinRoomsNorthSouth(rooms[7], rooms[8]);
	joinRoomsEastWest(rooms[8], rooms[9]);
	joinRoomsNorthSouth(rooms[10], rooms[9]);
	joinRoomsNorthSouth(rooms[9], rooms[11]);
	joinRoomsNorthSouth(rooms[12], rooms[10]);

	rooms[0]->addPlayer(player);
	playerRoom = 0;
}

void Dungeon::joinRoomsNorthSouth(Room* northRoom, Room* southRoom)
{
	southRoom->setNorthDoor(northRoom);
	northRoom->setSouthDoor(southRoom);
}

void Dungeon::joinRoomsEastWest(Room* eastRoom, Room* westRoom)
{
	westRoom->setEastDoor(eastRoom);
	eastRoom->setWestDoor(westRoom);
}

void Dungeon::movePlayer(int direction)
{
	switch(direction)
	{
		case Dungeon::NORTH:
		moveTo(rooms[playerRoom]->getNorthDoor());
		break;

		case Dungeon::EAST:
		moveTo(rooms[playerRoom]->getEastDoor());
		break;

		case Dungeon::SOUTH:
		moveTo(rooms[playerRoom]->getSouthDoor());
		break;

		case Dungeon::WEST:
		moveTo(rooms[playerRoom]->getWestDoor());
		break;

		default:
		std::cout << "Error: walking direction" << std::endl;
		break;
	}
}

void Dungeon::moveTo(Room* nextRoom)
{
	if(nextRoom)
	{
		nextRoom->addPlayer(rooms[playerRoom]->removePlayer());
		
		for(int x = 0; x < rooms.size(); x++)
		{
			if(rooms[x] == nextRoom)
			{
				playerRoom = x;
				break;
			}
		}
	}
	else
	{
		std::cout << "There is no door in that direction." << std::endl;
	}
}

Room* Dungeon::getActiveRoom()
{
	return rooms[playerRoom];
}