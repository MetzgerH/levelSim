#include "classes.h"


std::ostream& operator<<(std::ostream& lhs, className rhs)
{

}

void Barbarian::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 4, 2, 4, 1, 1, 1 };
	switch (this->getLevel())
	{
	case 4:
		weightedASI(weights);
		break;
	case 8:
		weightedASI(weights);
		break;
	case 12:
		weightedASI(weights);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	case 20:
		setAbility(abilityScore::constitution, getAbility(abilityScore::constitution) + 4);
		setAbility(abilityScore::strength, getAbility(abilityScore::strength) + 4);
	}
}

void Bard::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 1, 2, 1, 1, 4, 1 };
	switch (this->getLevel())
	{
	case 3:
		this->randExpertUpgrade();
		this->randExpertUpgrade();
		break;
	case 4:
		weightedASI(weights);
		break;
	case 8:
		weightedASI(weights);
		break;
	case 10:
		this->randExpertUpgrade();
		this->randExpertUpgrade();
		break;
	case 12:
		weightedASI(weights);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	}
}

void Cleric::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 3, 2, 3, 1, 6, 2 };
	switch (this->getLevel())
	{
	case 4:
		weightedASI(weights);
		break;
	case 8:
		weightedASI(weights);
		break;
	case 12:
		weightedASI(weights);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	}
}

void Druid::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 2, 2, 3, 1, 4, 1 };
	switch (this->getLevel())
	{
	case 4:
		weightedASI(weights);
		break;
	case 8:
		weightedASI(weights);
		break;
	case 12:
		weightedASI(weights);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	}
}

void Fighter::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 5, 2, 4, 1, 1, 1 };
	switch (this->getLevel())
	{
	case 4:
		weightedASI(weights);
		break; 
	case 6:
		weightedASI(weights);
		break;
	case 8:
		weightedASI(weights);
		break;
	case 12:
		weightedASI(weights);
		break;
	case 14:
		weightedASI(weights);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	}
}

void Monk::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 1, 6, 4, 1, 4, 1 };
	switch (this->getLevel())
	{
	case 4:
		weightedASI(weights);
		break;
	case 8:
		weightedASI(weights);
		break;
	case 12:
		weightedASI(weights);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	}

}

void Paladin::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 4, 2, 3, 1, 7, 2 };
	switch (this->getLevel())
	{
	case 4:
		weightedASI(weights);
		break;
	case 8:
		weightedASI(weights);
		break;
	case 12:
		weightedASI(weights);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	}
}

void Ranger::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 2, 3, 2, 1, 4, 1 };
	switch (this->getLevel())
	{
	case 4:
		weightedASI(weights);
		break;
	case 8:
		weightedASI(weights);
		break;
	case 12:
		weightedASI(weights);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	}
}

void Rogue::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 1, 7, 4, 4, 2, 4 };
	switch (this->getLevel())
	{
	case 4:
		weightedASI(weights);
		break;
	case 6:
		this->randExpertUpgrade();
		this->randExpertUpgrade();
		break;
	case 8:
		weightedASI(weights);
		break;
	case 12:
		weightedASI(weights);
		break;
	case 15:
		setSaveProf(abilityScore::wisdom);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	}
}

void Sorcerer::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 1, 4, 3, 1, 1, 6 };
	switch (this->getLevel())
	{
	case 4:
		weightedASI(weights);
		break;
	case 8:
		weightedASI(weights);
		break;
	case 12:
		weightedASI(weights);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	}
}

void Warlock::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 2, 3, 3, 2, 2, 8 };
	switch (this->getLevel())
	{
	case 4:
		weightedASI(weights);
		break;
	case 8:
		weightedASI(weights);
		break;
	case 12:
		weightedASI(weights);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	}
}

void Wizard::levelUp()
{
	this->Player::levelUp();
	int weights[7] = { 0, 1, 2, 4, 1, 1, 1 };
	switch (this->getLevel())
	{
	case 4:
		weightedASI(weights);
		break;
	case 8:
		weightedASI(weights);
		break;
	case 12:
		weightedASI(weights);
		break;
	case 16:
		weightedASI(weights);
		break;
	case 19:
		weightedASI(weights);
		break;
	}
}

std::string Barbarian::getClass()
{
	return "Barbarian";
}
std::string Bard::getClass()
{
	return "Bard";
}
std::string Cleric::getClass()
{
	return "Cleric";
}
std::string Druid::getClass()
{
	return "Druid";
}
std::string Fighter::getClass()
{
	return "Fighter";
}
std::string Monk::getClass()
{
	return "Monk";
}
std::string Paladin::getClass()
{
	return "Paladin";
}
std::string Ranger::getClass()
{
	return "Ranger";
}
std::string Rogue::getClass()
{
	return "Rogue";
}
std::string Sorcerer::getClass()
{
	return "Sorcerer";
}
std::string Warlock::getClass()
{
	return "Warlock";
}
std::string Wizard::getClass()
{
	return "Wizard";
}