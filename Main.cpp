/*
	Alex Pacheco
	COMP 340 - Project 1
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "Goblin.hpp"
#include "Orc.hpp"
#include "Player.hpp"
#include "Dungeon.hpp"

//DECLARE VARIABLES AND FUNCTIONS USED IN Main.cpp
Dungeon* dungeon;
Player* player;
bool continueGame = true;
int invalidInputCounter = 0;
void doAction(std::string userInput);
void printMenu();

int main()
{
	srand(time(NULL));

	std::string str_userInput;

	std::cout << "Enter name for player: ";
	getline(std::cin, str_userInput);
	player = new Player(str_userInput);

	std::cout << std::endl;

	std::cout << "Welcome " << str_userInput << "!" << std::endl;
	std::cout << "Health    " << player->getCurrentHealth() << std::endl;
	std::cout << "Attack    " << player->getBaseAttackStat() << std::endl;
	std::cout << "Defense   " << player->getBaseDefenseStat() << std::endl;
	std::cout << "Speed     " << player->getBaseSpeedStat() << std::endl;

	std::cout << std::endl;
	printMenu();
	std::cout << std::endl;

	std::cout	<< "You have been kidnapped and brought to a dungeon by your" << std:: endl
				<< "captors and left to die. You want to escape, but you only" << std::endl
				<< "have a simple map and are trapped in a small room. There is" << std::endl
				<< "one door in front of you, so you decide to walk through it." << std::endl
				<< std::endl;

	dungeon = new Dungeon(player);

	do
	{
		Room* activeRoom = dungeon->getActiveRoom();
		if(activeRoom->getEnemy())
		{
			Character* enemy = activeRoom->getEnemy();
			if(enemy->getCurrentHealth() <= 0)
			{
				activeRoom->destroyEnemy();
			}
			else
			{
				enemy->setAttackTarget(player);
				enemy->update();
			}
			player->setAttackTarget(activeRoom->getEnemy());
		}

		if(player->getCurrentHealth() <= 0)
		{
			std::cout << std::endl << "GAME OVER!" << std::endl << std::endl;
			continueGame = false;
		}
		else
		{
			doAction(player->update());
		}
	} while(continueGame);
}

void doAction(std::string userInput)
{
	std::transform(
		userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

	if(userInput == "inventory")
	{
		player->printInventory();
	}
	else if(userInput == "search")
	{
		Item* item = dungeon->getActiveRoom()->getItem(false);
		if(item)
		{
			std::cout << "After searching the room, you find a "
				<< item->getName() << std::endl;
		}
		else
		{
			std::cout << "There do not appear to be any items in the room"
				<< std::endl;
		}
	}
	else if(userInput == "take item")
	{
		player->addItem(dungeon->getActiveRoom()->getItem(true));
	}
	else if(userInput == "use potion")
	{
		Item* item = player->removeItem("Potion");
		if(item)
		{
			item->use(player);
		}
	}
	else if(userInput == "use grenade")
	{
		Item* item = player->removeItem("Grenade");
		if(item)
		{
			if(dungeon->getActiveRoom()->getEnemy())
			{
				item->use(dungeon->getActiveRoom()->getEnemy());
			}
			else
			{
				std::cout << "There is no enemy around, and the "
					<< "grenade blows up on you." << std::endl;
				item->use(player);
			}
		}
	}
	else if(userInput == "attack")
	{
		player->executeAttack();
	}
	else if(userInput == "walk north")
	{
		if(dungeon->getActiveRoom()->getEnemy())
		{
			std::cout << "You can't leave! There is an enemy nearby!" << std::endl;
		}
		else
		{
			dungeon->movePlayer(Dungeon::NORTH);
		}
	}
	else if(userInput == "walk south")
	{
		if(dungeon->getActiveRoom()->getEnemy())
		{
			std::cout << "You can't leave! There is an enemy nearby!" << std::endl;
		}
		else
		{
			dungeon->movePlayer(Dungeon::SOUTH);
		}
	}
	else if(userInput == "walk east")
	{
		if(dungeon->getActiveRoom()->getEnemy())
		{
			std::cout << "You can't leave! There is an enemy nearby!" << std::endl;
		}
		else
		{
			dungeon->movePlayer(Dungeon::EAST);
		}
	}
	else if(userInput == "walk west")
	{
		if(dungeon->getActiveRoom()->getEnemy())
		{
			std::cout << "You can't leave! There is an enemy nearby!" << std::endl;
		}
		else
		{
			dungeon->movePlayer(Dungeon::WEST);
		}
	}
	else if(userInput == "view map")
	{
		std::cout << std::endl
			<< "    [ ]                          N" << std::endl
			<< "     |                         W + E" << std::endl
			<< "    [ ]  [ ]--[ ]--[ ]           S" << std::endl
			<< "     |    |         |" << std::endl
			<< "    [ ]--[ ]       [ ]" << std::endl
			<< "     |              |" << std::endl
			<< "    [ ]       [ ]--[ ]--[ ]" << std::endl
			<< "                    |" << std::endl
			<< "                   [ ]" << std::endl
			<< std::endl;
	}
	else if(userInput == "help")
	{
		printMenu();
	}
	else if(userInput == "quit")
	{
		continueGame = false;
	}
	else
	{
		std::cout << "Invalid input!" << std::endl;

		invalidInputCounter++;
		if(invalidInputCounter == 2)
		{
			std::cout << "Please type 'help' for a list of valid commands."
				<< std::endl;
			invalidInputCounter = 0;
		}
	}
}

void printMenu()
{
	std::cout << "'view map'        "
		<< "Look at a simple map of the dungeon" << std::endl;
	std::cout << "'walk north'      "
		<< "Move player north" << std::endl;
	std::cout << "'walk south'      "
		<< "Move player south" << std::endl;
	std::cout << "'walk east'       "
		<< "Move player east" << std::endl;
	std::cout << "'walk west'       "
		<< "Move player west" << std::endl;
	std::cout << "'attack'          "
		<< "Attack enemy" << std::endl;
	std::cout << "'search'          "
		<< "Search the room for items" << std::endl;
	std::cout << "'inventory'       "
		<< "List items in player inventory" << std::endl;
	std::cout << "'take item'       "
		<< "Take the item in the room" << std::endl;
	std::cout << "'use [item]'      "
		<< "Use the item specified" << std::endl;
	std::cout << "'help'            "
		<< "Reprint menu options" << std::endl;
	std::cout << "'quit'            "
		<< "Quit the game" << std::endl;
}