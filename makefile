all: TextGame

TextGame:  Main.cpp Character.cpp Goblin.cpp FastGoblin.cpp RegenGoblin.cpp NormalGoblin.cpp Orc.cpp NormalOrc.cpp SuperOrc.cpp ArmoredOrc.cpp Item.cpp Potion.cpp Grenade.cpp Player.cpp Room.cpp Dungeon.cpp
	g++ Main.cpp Character.cpp Goblin.cpp FastGoblin.cpp RegenGoblin.cpp NormalGoblin.cpp Orc.cpp NormalOrc.cpp SuperOrc.cpp ArmoredOrc.cpp Item.cpp Potion.cpp Grenade.cpp Player.cpp Room.cpp Dungeon.cpp -std=c++11 -o AdventureGame