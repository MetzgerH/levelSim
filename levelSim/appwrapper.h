#pragma once

#include "player.h"

#define MAXPARTYSIZE 10
#define SIMSIZE 1000

class Appwrapper
{
private:
	Player playerSet[MAXPARTYSIZE][SIMSIZE]; //array of list heads
	int playerCount;
	std::mt19937 rng;
	bool addBackground;
	bool addLineage;
	int choosePlayer();
	void displayAbilities();
	void displayTools();
public:
	Appwrapper()
	{
		addBackground = true;
#ifndef ONEDND
		addLineage = true;
#endif
#ifdef ONEDND
		addLineage = false;
#endif
		playerCount = 0;
		rng = std::mt19937(time(NULL));
	}
	~Appwrapper();
	void deletePlayer(int playerNum);
	void addPlayer(className classToAdd);

	double getAverageMod(int targetPlayer, skillName targetSkill, abilityScore targetAbility = (abilityScore)0, toolName targetTool= (toolName)0);
	//O(n) where n = simSize

	double getAverageMod(skillName targetSkill, abilityScore targetAbility = (abilityScore)0, toolName targetTool = (toolName)0);
	//averages whole party

	double getAverageMod(int targetPlayer, skillName targetSkill, toolName targetTool);
	double getAverageMod(skillName targetSkill, toolName targetTool);

	double getAverageSave(int targetPlayer, abilityScore targetAbility);

	double getAverageHealth(int targetPlayer);
	double getAverageHealth();

	void runApp();
	void displayMainMenu();
	void displayClassMenu();
	void displaySkillsMenu();
	void displayPlayers();


};
