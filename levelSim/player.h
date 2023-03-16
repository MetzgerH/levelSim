#pragma once

#include <string>
#include <iostream>
#include <random>

#include "skill.h"
#include "tool.h"

#define ONEDND //certain functions are replaced via preprocessing if this line is here.

#ifndef ONEDND
enum class background : char
{
	acolyte = 1, charlatan, criminal, entertainer, folkHero, guildArtisan, hermit, noble, outlander, sailor, soldier, urchin, max
};
#endif

#ifdef ONEDND
enum class background : char
{
	acolyte = 1, artisan, charlatan, criminal, cultist, entertainer, farmer, gladiator, guard, guide, hermit,laborer,noble,pilgrim,sage, sailor, soldier, urchin, max
};
#endif

enum class className : char
{
	barbarian = 1, bard, cleric, druid, fighter, monk, paladin, ranger, rogue, sorcerer, warlock, wizard, max
};

std::ostream& operator<<(std::ostream& lhs, className rhs);
std::string toString(className input);

class Player
{
private:
	className coreClass;
	Skill skillSet[(int)skillName::max];
	Skill saveSet[(int)abilityScore::max];
	void initializeSkillSet(); //also initializes saveSet
	int abilities[(int)abilityScore::max];
	int proficiencyBonus;
	int hitDie;
	int maxHealth;
	int healthFromRolls;
	int level;
	void pickSkillsRandomly();
	ToolNode* toolHead;
	std::mt19937* rng;
	int addSkillOutOf(skillName* options, int optionCount); //returns 0 if all skills are proficient, or 1 if it successfully adds a skill
	// O(n) where n = optionCount
	void setAbility(abilityScore targetAbility, int newScore);
public:
	Player(className newClass = (className)1, std::mt19937* newrng = nullptr)
	{
		for (int count = 0; count < (int) abilityScore::max; count++)
			abilities[count] = 0;
		initializeSkillSet();
		proficiencyBonus = 2;
		
		level = 1;
		rng = newrng;
		toolHead = nullptr;
		coreClass = newClass;



		//class specifics
		switch (coreClass)
		{
		case className::barbarian:
			setSaveProf(abilityScore::constitution);
			setSaveProf(abilityScore::strength);
			standardArray(abilityScore::constitution, abilityScore::strength, abilityScore::dexterity);
			hitDie = 12;
			break;
		case className::bard:
			setSaveProf(abilityScore::charisma);
			setSaveProf(abilityScore::dexterity);
			standardArray(abilityScore::charisma, abilityScore::dexterity);
			hitDie = 8;
			break;
		case className::cleric:
			setSaveProf(abilityScore::wisdom);
			setSaveProf(abilityScore::charisma);
			standardArray(abilityScore::wisdom);
			hitDie = 8;
			break;
		case className::druid:
			setSaveProf(abilityScore::intelligence);
			setSaveProf(abilityScore::wisdom);
			standardArray(abilityScore::wisdom);
			hitDie = 8;
			break;
		case className::fighter:
			setSaveProf(abilityScore::constitution);
			setSaveProf(abilityScore::strength);
			standardArray(abilityScore::strength, abilityScore::constitution, abilityScore::dexterity);
			hitDie = 10;
			break;
		case className::monk:
			setSaveProf(abilityScore::dexterity);
			setSaveProf(abilityScore::strength);
			standardArray(abilityScore::dexterity, abilityScore::constitution, abilityScore::wisdom);
			hitDie = 8;
			break;
		case className::paladin:
			setSaveProf(abilityScore::wisdom);
			setSaveProf(abilityScore::charisma);
			standardArray(abilityScore::charisma, abilityScore::constitution);
			hitDie = 10;
			break;
		case className::ranger:
			setSaveProf(abilityScore::dexterity);
			setSaveProf(abilityScore::strength);
			standardArray(abilityScore::wisdom, abilityScore::dexterity, abilityScore::constitution);
			hitDie = 10;
			break;
		case className::rogue:
			setSaveProf(abilityScore::dexterity);
			setSaveProf(abilityScore::intelligence);
			standardArray(abilityScore::dexterity, abilityScore::charisma, abilityScore::intelligence);
			hitDie = 8;
			break;
		case className::sorcerer:
			setSaveProf(abilityScore::charisma);
			setSaveProf(abilityScore::constitution);
			standardArray(abilityScore::charisma);
			hitDie = 6;
			break; 
		case className::warlock:
			setSaveProf(abilityScore::wisdom);
			setSaveProf(abilityScore::charisma);
			standardArray(abilityScore::charisma);
			hitDie = 8;
			break; 
		case className::wizard:
			setSaveProf(abilityScore::intelligence);
			setSaveProf(abilityScore::wisdom);
			standardArray(abilityScore::intelligence, abilityScore::dexterity);
			hitDie = 6;
			break;
		} 

		pickSkillsRandomly();
		healthFromRolls = hitDie;
		maxHealth = healthFromRolls;
	}
	Player(className newClass, int scores[(int)abilityScore::max], std::mt19937* newrng = nullptr) : Player(newClass, newrng)
	{
		for (int count = 1; count < (int)abilityScore::max; count++)
			abilities[count] = scores[count];
		updateHealth();
	}
	Player(Player& copy)
	{
		this->coreClass = copy.coreClass;
		for (int count = 0; count < (int)skillName::max; count++)
			this->skillSet[count] = copy.skillSet[count];
		for (int count = 0; count < (int)abilityScore::max; count++)
		{
			this->saveSet[count] = copy.saveSet[count];
			this->abilities[count] = copy.abilities[count];
		}
		this->proficiencyBonus = copy.proficiencyBonus;
		this->hitDie = copy.hitDie;
		this->maxHealth = copy.maxHealth;
		this->healthFromRolls = copy.healthFromRolls;
		this->level = copy.level;
		if (copy.toolHead == nullptr)
			this->toolHead = nullptr;
		else
		{
			ToolNode* pCurrentCopy = copy.toolHead;
			this->toolHead = new ToolNode(pCurrentCopy->getID(), pCurrentCopy->isExpert());
			pCurrentCopy = pCurrentCopy->getNext();
			ToolNode* pCurrentThis = this->toolHead->getNext();
			while (pCurrentCopy != nullptr)
			{
				pCurrentThis->setNext(new ToolNode(pCurrentCopy->getID(), pCurrentCopy->isExpert()));
				pCurrentCopy = pCurrentCopy->getNext();
				pCurrentThis = pCurrentThis->getNext();
			}
		}
		this->rng = copy.rng;
	}

	int getSkillMod(skillName targetSkill); 
	int getSkillMod(skillName targetSkill, abilityScore targetAbility);
	int getSkillMod(skillName targetSkill, toolName targetTool);
	int getSkillMod(skillName targetSkill, abilityScore targetAbility, toolName targetTool);
	int getSaveMod(abilityScore targetSave);
	int getHealth();
	int getLevel();
	int getAbility(abilityScore targetAbility);
	int getInitiative();
	
	bool hasProficiency(skillName targetSkill);
	bool hasProficiency(toolName targetTool);
	bool hasExpertise(toolName targetTool);

	void updateHealth();
	void levelUp();
	int randExpertUpgrade(); //returns 0 if it fails, or 1 if it succeeds

	int setSaveProf(abilityScore targetSave, bool prof = true); //returns 0 if it fails, or 1 if it succeeds
	int gainProficiency(skillName targetSkill); //returns 0 if it fails, or 1 if it succeeds
	int gainTool(toolName targetTool);
	void gainTool();

	int getProfBonus();

	void standardArray();
	void standardArray(abilityScore priority);
	void standardArray(abilityScore priority1, abilityScore priority2);
	void standardArray(abilityScore priority1, abilityScore priority2, abilityScore priority3);

	void randomCustomLineage();

	void randomASI();
	void weightedASI(int weights[(int)abilityScore::max]); //weights is an array of 0, followed by the weight for each ability score (in order of the abilityScore enum)

	void addBackground(background newBackground);
	void addBackground();

	className getClass();

	void setRNG(std::mt19937* newRNG);
	int d(int dieSize);
};