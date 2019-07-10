#include "Character.hpp"

Character::Character(std::string name, double baseHealthStat,
		double baseAttackStat, double baseDefenseStat, double baseSpeedStat)
{
	this->name = name;
	this->baseHealthStat = baseHealthStat;
	this->baseAttackStat = baseAttackStat;
	this->baseDefenseStat = baseDefenseStat;
	this->baseSpeedStat = baseSpeedStat;
	this->currentHealth = baseHealthStat;
}

std::string Character::getName()
{
	return this->name;
}

int Character::getCurrentHealth()
{
	return this->currentHealth;
}

void Character::addHealth(int amount)
{
	this->currentHealth += amount;
	
	if(this->currentHealth > this->baseHealthStat)
	{
		this->currentHealth = this->baseHealthStat;
	}

	if(this->currentHealth <= 0)
	{
		std::cout << this->name << " died." << std::endl;
	}
	else
	{
		std::cout << this->name << "'s Health: "
			<< this->currentHealth << std::endl;
	}
}

double Character::getBaseHealthStat()
{
	return this->baseHealthStat;
}

double Character::getBaseAttackStat()
{
	return this->baseAttackStat;
}

double Character::getBaseDefenseStat()
{
	return this->baseDefenseStat;
}

double Character::getBaseSpeedStat()
{
	return this->baseSpeedStat;
}

void Character::attack(Character* target, double damage)
{
	if(target)
	{
		double multiplier = this->baseAttackStat / target->getBaseDefenseStat();

		int healthChange = multiplier * damage;

		srand(time(NULL));
		int hit = rand() % 200;
		if(hit < target->getBaseSpeedStat())	// target evaded attack
		{
			healthChange = 0;
			std::cout << this->name << "'s attack missed! ";
		}
		else
		{
			std::cout << this->name << " attacked and did "
				<< healthChange << " damage! ";
		}
		target->addHealth(-healthChange);
	}
	else
	{
		std::cout << "No enemy to attack" << std::endl;
	}
}

void Character::setAttackTarget(Character* target)
{
	this->target = target;
}