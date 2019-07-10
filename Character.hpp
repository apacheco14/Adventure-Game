#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include <ctime>

class Character
{
protected:
	std::string name;
	int currentHealth;
	double baseHealthStat;
	double baseAttackStat;
	double baseDefenseStat;
	double baseSpeedStat;
	Character* target;

public:
	Character(std::string name, double baseHealthStat, double baseAttackStat,
		double baseDefenseStat, double baseSpeedStat);
	std::string getName();
	int getCurrentHealth();
	void addHealth(int amount);
	double getBaseHealthStat();
	double getBaseAttackStat();
	double getBaseDefenseStat();
	double getBaseSpeedStat();
	void attack(Character* target, double damage);
	void setAttackTarget(Character* target);
	virtual std::string update() = 0;
};

#endif