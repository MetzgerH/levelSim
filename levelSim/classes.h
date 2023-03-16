#pragma once

#include "player.h"
#include <chrono>

enum class className
{
	barbarian = 1, bard, cleric, druid, fighter, monk, paladin, ranger, rogue, sorcerer, warlock, wizard, max
};

std::ostream& operator<<(std::ostream& lhs, className rhs);


class Barbarian : public Player
{
private:
	void pickSkillsRandomly();
public:
	Barbarian(std::mt19937* newrng = nullptr) : Player (12, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::constitution);
		setSaveProf(abilityScore::strength);
		standardArray(abilityScore::constitution, abilityScore::strength, abilityScore::dexterity);
	}
	Barbarian(int scores[7], std::mt19937* newrng = nullptr) : Player(12, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::constitution);
		setSaveProf(abilityScore::strength);
	}
	void levelUp();
	std::string getClass();
};


class Bard : public Player
{
private:
	void pickSkillsRandomly();
public:
	Bard(std::mt19937* newrng = nullptr) : Player(8, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::dexterity);
		setSaveProf(abilityScore::charisma);
		standardArray(abilityScore::charisma, abilityScore::dexterity);
	}
	Bard(int scores[7], std::mt19937* newrng = nullptr) : Player(8, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::dexterity);
		setSaveProf(abilityScore::charisma);
	}
	void levelUp();
	std::string getClass();
};

class Cleric : public Player
{
private:
	void pickSkillsRandomly();
public:
	Cleric(std::mt19937* newrng = nullptr) : Player(8, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::wisdom);
		setSaveProf(abilityScore::charisma);
		standardArray(abilityScore::wisdom);
	}
	Cleric(int scores[7], std::mt19937* newrng = nullptr) : Player(8, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::wisdom);
		setSaveProf(abilityScore::charisma);
	}
	void levelUp();
	std::string getClass();
};

class Druid : public Player
{
private:
	void pickSkillsRandomly();
public:
	Druid(std::mt19937* newrng = nullptr) : Player(8, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::intelligence);
		setSaveProf(abilityScore::wisdom);
		standardArray(abilityScore::wisdom);
	}
	Druid(int scores[7], std::mt19937* newrng = nullptr) : Player(8, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::intelligence);
		setSaveProf(abilityScore::wisdom);
	}
	void levelUp();
	std::string getClass();
};

class Fighter : public Player
{
private:
	void pickSkillsRandomly();
public:
	Fighter(std::mt19937* newrng = nullptr) : Player(10, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::dexterity);
		setSaveProf(abilityScore::strength);
		standardArray(abilityScore::strength, abilityScore::constitution, abilityScore::dexterity);
	}
	Fighter(int scores[7], std::mt19937* newrng = nullptr) : Player(10, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::dexterity);
		setSaveProf(abilityScore::strength);
	}
	void levelUp();
	std::string getClass();
};

class Monk : public Player
{
private:
	void pickSkillsRandomly();
public:
	Monk(std::mt19937* newrng = nullptr) : Player(8, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::dexterity);
		setSaveProf(abilityScore::wisdom);
		standardArray(abilityScore::dexterity, abilityScore::constitution, abilityScore::wisdom);
	}
	Monk(int scores[7], std::mt19937* newrng = nullptr) : Player(8, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::dexterity);
		setSaveProf(abilityScore::wisdom);
	}
	void levelUp();
	std::string getClass();
};

class Paladin : public Player
{
private:
	void pickSkillsRandomly();
public:
	Paladin(std::mt19937* newrng = nullptr) : Player(10, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::wisdom);
		setSaveProf(abilityScore::charisma);
		standardArray(abilityScore::charisma, abilityScore::constitution);
	}
	Paladin(int scores[7], std::mt19937* newrng = nullptr) : Player(10, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::wisdom);
		setSaveProf(abilityScore::charisma);
	}
	void levelUp();
	std::string getClass();
};

class Ranger : public Player
{
private:
	void pickSkillsRandomly();
public:
	Ranger(std::mt19937* newrng = nullptr) : Player(10, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::dexterity);
		setSaveProf(abilityScore::strength);
		standardArray(abilityScore::wisdom, abilityScore::dexterity, abilityScore::constitution);
	}
	Ranger(int scores[7], std::mt19937* newrng = nullptr) : Player(10, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::dexterity);
		setSaveProf(abilityScore::strength);
	}
	void levelUp();
	std::string getClass();
};

class Rogue : public Player
{
private:
	void pickSkillsRandomly();
public:
	Rogue(std::mt19937* newrng = nullptr) : Player(8, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::intelligence);
		setSaveProf(abilityScore::dexterity);
		standardArray(abilityScore::dexterity,abilityScore::charisma, abilityScore::intelligence);
	}
	Rogue(int scores[7],std::mt19937* newrng = nullptr) : Player(8, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::intelligence);
		setSaveProf(abilityScore::dexterity);
	}
	void levelUp();
	std::string getClass();
};

class Sorcerer : public Player
{
private:
	void pickSkillsRandomly();
public:
	Sorcerer(std::mt19937* newrng = nullptr) : Player(6, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::constitution);
		setSaveProf(abilityScore::charisma);
		standardArray(abilityScore::charisma);
	}
	Sorcerer(int scores[7], std::mt19937* newrng = nullptr) : Player(6, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::constitution);
		setSaveProf(abilityScore::charisma);
	}
	void levelUp();
	std::string getClass();
};

class Warlock : public Player
{
private:
	void pickSkillsRandomly();
public:
	Warlock(std::mt19937* newrng = nullptr) : Player(8, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::wisdom);
		setSaveProf(abilityScore::charisma);
		standardArray(abilityScore::charisma);
	}
	Warlock(int scores[7], std::mt19937* newrng = nullptr) : Player(8, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::wisdom);
		setSaveProf(abilityScore::charisma);
	}
	void levelUp();
	std::string getClass();
};

class Wizard : public Player
{
private:
	void pickSkillsRandomly();
public:
	Wizard(std::mt19937* newrng = nullptr) : Player(6, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::intelligence);
		setSaveProf(abilityScore::wisdom);
		standardArray(abilityScore::intelligence, abilityScore::dexterity);
	}
	Wizard(int scores[7], std::mt19937* newrng = nullptr) : Player(6, scores, newrng)
	{
		pickSkillsRandomly();
		setSaveProf(abilityScore::intelligence);
		setSaveProf(abilityScore::wisdom);
	}
	void levelUp();
	std::string getClass();
};