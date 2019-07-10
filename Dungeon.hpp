#ifndef DUNGEON_HPP
#define DUNGEON_HPP

#include <string>
#include <vector>
#include <iostream>

#include "Room.hpp"
#include "Player.hpp"

class Dungeon
{
private:
	Player* player;
	std::vector<Room*> rooms;
	int playerRoom;
	void joinRoomsNorthSouth(Room* northRoom, Room* southRoom);
	void joinRoomsEastWest(Room* eastRoom, Room* westRoom);
	void moveTo(Room* nextRoom);

public:
	Dungeon(Player* player);
	static const int NORTH = 0;
	static const int EAST = 1;
	static const int SOUTH = 2;
	static const int WEST = 3;
	void movePlayer(int direction);
	Room* getActiveRoom();
};

#endif