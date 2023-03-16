#include "appwrapper.h"

Appwrapper::~Appwrapper()
{
	for (int count = 0; count < MAXPARTYSIZE; count++)
		deletePlayer(count);
}

void Appwrapper::deletePlayer(int playerNum)
{
	if (playerNum >= playerCount)
		return;
	playerCount--;
	for (int count = playerNum; count < playerCount; count++)
	{
		for (int tally = 0; tally < SIMSIZE; tally++)
		{
			playerSet[count][tally] = playerSet[count + 1][tally];
		}
	}
}


void Appwrapper::addPlayer(className classToAdd)
{
	for (int count = 0; count < SIMSIZE; count++)
	{
		playerSet[playerCount][count] = Player(classToAdd, &(this->rng));
		if (this->addBackground)
			playerSet[playerCount][count].addBackground();

		if (this->addLineage)
			playerSet[playerCount][count].randomCustomLineage();
	}
	playerCount++;
}

double Appwrapper::getAverageMod(int targetPlayer, skillName targetSkill, abilityScore targetAbility, toolName targetTool)
{
	if (targetPlayer >= playerCount)
	{
		std::cout << "ERROR targeting a non-existant player with getAverageMod()" << std::endl;
		return 0;
	}
	double total = 0;
	for (int count = 0; count < SIMSIZE; count++)
	{
		if ((int)targetAbility == 0)
			total += playerSet[targetPlayer][count].getSkillMod(targetSkill);
		else
		{
			if ((int)targetTool == 0)
				total += playerSet[targetPlayer][count].getSkillMod(targetSkill, targetAbility);
			else
				total += playerSet[targetPlayer][count].getSkillMod(targetSkill, targetAbility, targetTool);
		}
	}
	return (double)total / SIMSIZE;
}

double Appwrapper::getAverageMod(int targetPlayer, skillName targetSkill, toolName targetTool)
{
	if (targetPlayer >= playerCount)
	{
		std::cout << "ERROR targeting a non-existant player with getAverageMod()" << std::endl;
		return 0;
	}
	double total = 0;
	for (int count = 0; count < SIMSIZE; count++)
	{
		
		total += playerSet[targetPlayer][count].getSkillMod(targetSkill, targetTool);
		
	}
	return (double)total / SIMSIZE;
}


double Appwrapper::getAverageHealth(int targetPlayer)
{
	if (targetPlayer >= playerCount)
	{
		std::cout << "ERROR targeting a non-existant player with getAverageHealth()" << std::endl;
		return 0;
	}
	int total = 0;
	for (int count = 0; count < SIMSIZE; count++)
	{

		total += playerSet[targetPlayer][count].getHealth();

	}
	return (double)total / SIMSIZE;
}

double Appwrapper::getAverageMod(skillName targetSkill, abilityScore targetAbility, toolName targetTool)
{
	if (playerCount == 0)
	{
		std::cout << "ERROR: calling getAverageMod() with an empty party" << std::endl;
		return 0;
	}
	double total = 0;
	for (int count = 0; count < playerCount; count++)
	{
			total += this->getAverageMod(count, targetSkill, targetAbility, targetTool);
	}
	return total / playerCount;
}

double Appwrapper::getAverageMod(skillName targetSkill, toolName targetTool)
{
	if (playerCount == 0)
	{
		std::cout << "ERROR: calling getAverageMod() with an empty party" << std::endl;
		return 0;
	}
	double total = 0;
	for (int count = 0; count < playerCount; count++)
	{
		
			total += this->getAverageMod(count, targetSkill, targetTool);
	}
	return total / playerCount;
}

double Appwrapper::getAverageSave(int targetPlayer, abilityScore targetAbility)
{
	if (targetPlayer >= playerCount)
	{
		std::cout << "ERROR targeting a non-existant player with getAverageHealth()" << std::endl;
		return 0;
	}
	int total = 0;
	for (int count = 0; count < SIMSIZE; count++)
	{

		total += playerSet[targetPlayer][count].getSaveMod(targetAbility);

	}
	return (double)total / SIMSIZE;
}

double Appwrapper::getAverageHealth()
{
	if (playerCount == 0)
	{
		std::cout << "ERROR: calling getAverageHealth() with an empty party" << std::endl;
		return 0;
	}
	double total = 0;
	for (int count = 0; count < playerCount; count++)
	{

		total += this->getAverageHealth(count);
	}
	return total / playerCount;
}


void Appwrapper::runApp()
{
	int option = 0;
	int subOption;
	skillName targetSkill;
	toolName targetTool;
	abilityScore targetAbility;
	int temp;
	while (option != 12)
	{
		
		switch (option)
		{
		case 1:

			subOption = 0;
			while (subOption<1 || subOption>(int)className::max)
			{
				system("cls");
				std::cout << "Please choose a class" << std::endl;
				displayClassMenu();
				std::cin >> subOption;
			}
			addPlayer((className)subOption);
			break;
		case 2:
			subOption = choosePlayer();
			deletePlayer(subOption);
			break;
		case 3:
			subOption = choosePlayer();
			std::cout << "Player: " << subOption+1 << " has an average health of " << getAverageHealth(subOption) << std::endl;
			system("pause");
			break;
		case 4:
			std::cout << "The party has an average health of " << getAverageHealth() << std::endl;
			system("pause");
			break;
		case 5:
			subOption = choosePlayer();
			std::cout << "Please choose a skill" << std::endl;
			displaySkillsMenu();
			temp = -1;
			while (temp < 0 || temp >= (int)skillName::max)
				std::cin >> temp;
			targetSkill = (skillName)temp;
			std::cout << "Please choose an ability or enter any number > 6 for default ability" << std::endl;
			displayAbilities();
			std::cin >> temp;
			if (temp < 1 || temp >6)
				targetAbility = (abilityScore)0;
			else
				targetAbility = (abilityScore)temp;
			std::cout << "Please choose a tool or enter any number > " << (int)toolName::max - 1 << " for no tool" << std::endl;
			displayTools();
			std::cin >> temp;
			if (temp< 1 || temp >(int)toolName::max - 1)
			{
				std::cout << "Player " << subOption+1 << ": has an average " << targetSkill << " modifier of " << this->getAverageMod(subOption, targetSkill, targetAbility) << std::endl;
			}
			else
			{
				targetTool = (toolName)temp;
				if (targetAbility != (abilityScore)0)
					std::cout << "Player " << subOption+1 << ": has an average " << targetSkill << " modifier with " << targetTool << " of " <<
					this->getAverageMod(subOption, targetSkill, targetAbility, targetTool) << std::endl;
				else
					std::cout << "Player " << subOption+1 << ": has an average " << targetSkill << " modifier with " << targetTool << " of " <<
					this->getAverageMod(subOption, targetSkill, targetTool) << std::endl;
			}
			system("pause");
			break;
		case 6:
			std::cout << "Please choose a skill" << std::endl;
			displaySkillsMenu();
			temp = -1;
			while (temp < 0 || temp >= (int)skillName::max)
				std::cin >> temp;
			targetSkill = (skillName)temp;
			std::cout << "Please choose an ability or enter any number > 6 for default ability" << std::endl;
			displayAbilities();
			std::cin >> temp;
			if (temp < 1 || temp >6)
				targetAbility = (abilityScore)0;
			else
				targetAbility = (abilityScore)temp;
			std::cout << "Please choose a tool or enter any number > " << (int)toolName::max - 1 << "for no tool" << std::endl;
			displayTools();
			std::cin >> temp;
			if (temp< 1 || temp >(int)toolName::max - 1)
			{
				std::cout << "The party has an average " << targetAbility << " (" << targetSkill << ") modifier of " << this->getAverageMod(targetSkill, targetAbility) << std::endl;
			}
			else
			{
				targetTool = (toolName)temp;
				if (targetAbility != (abilityScore)0)
					std::cout << "The party has an average " << targetAbility <<" (" << targetSkill << ") modifier with " << targetTool << " of " <<
					this->getAverageMod(targetSkill, targetAbility, targetTool) << std::endl;
				else
					std::cout << "The party has an average " << targetSkill << " modifier with " << targetTool << " of " <<
					this->getAverageMod(targetSkill, targetTool) << std::endl;
			}
			system("pause");
			break;
		case 7:
			subOption = choosePlayer();
			std::cout << "Please choose an ability score";
			do {
				displayAbilities();
				std::cin >> temp;
			} while (temp < 0 || temp >= (int)abilityScore::max);
			std::cout << "Player " << subOption + 1 << " has an average " << temp << " saving throw modifier of " << this->getAverageSave(subOption, abilityScore(temp)) << std::endl;
			system("pause");
			break;
		case 8:
			subOption = choosePlayer();
			switch (playerSet[subOption][0].getClass())
			{
			case className::barbarian:
				std::cout << "Player " << subOption + 1 << "has no save DC" << std::endl;
				break;
			case className::bard:
				std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::charisma) + 8<< std::endl;
				break;
			case className::cleric:
				std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::wisdom) + 8 << std::endl;
				break;
			case className::druid:
				std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::wisdom) + 8 << std::endl;
				break;
			case className::fighter:
				std::cout << "Do you want this fighter's save DC based on intelligence (eldritch knight) or strength (battlemaster)?" << std::endl << "1. intelligence"
					<< std::endl << "2. strength";
				do
				{
					std::cin >> temp;
				} while (temp < 1 || temp >2);
				if (temp == 1)
					std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::intelligence) + this->playerSet[subOption][0].getProfBonus() + 8 << std::endl;
				else
					std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::strength) + 8 << std::endl;
				break;
			case className::monk:
				std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::wisdom) + 8 << std::endl;
				break;
			case className::paladin:
				std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::charisma) + 8 << std::endl;
				break;
			case className::ranger:
				std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::wisdom) + 8 << std::endl;
				break;
			case className::rogue:
				std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::intelligence) + 8 << std::endl;
				break;
			case className::sorcerer:
				std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::charisma) + 8 << std::endl;
				break;
			case className::warlock:
				std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::charisma) + 8 << std::endl;
				break;
			case className::wizard:
				std::cout << "Player " << subOption + 1 << " has an average Save DC of " << this->getAverageSave(subOption, abilityScore::intelligence) + 8 << std::endl;
				break;
			}
			system("pause");
			break;
		case 9:
			subOption = choosePlayer();
			for (int count = 0; count < SIMSIZE; count++)
			{
				playerSet[subOption][count].levelUp();
			}
			break;
		case 10:
			for(int currentPlayer = 0; currentPlayer< playerCount; currentPlayer++)
				for (int count = 0; count < SIMSIZE; count++)
				{
					playerSet[currentPlayer][count].levelUp();
				}
			break;
		}
		system("cls");
		displayMainMenu();
		std::cin >> option;
	}
}

int Appwrapper::choosePlayer()
{
	int output = 0;
	while (output<1 || output> playerCount)
	{
		system("cls");
		std::cout << "Please choose a player" << std::endl;
		displayPlayers();
		std::cin >> output;
	}
	return output-1;
}

void Appwrapper::displayMainMenu()
{
	std::cout << "1. Add a player" << std::endl << "2. Delete a player" << std::endl << "3. Get a player's average health" << std::endl <<
		"4. Get the party's average health" << std::endl << "5. Get a player's average modifier for a skill" << std::endl <<
		"6. Get the party's average modifier for a skill" << std::endl << "7. Get a player's saving throw modifier" << std::endl << "8. Get a player's Save DC" <<
		std::endl << "9. Level up a player" << std::endl << "10. Level up the entire party" << std::endl << "11. Change settings" << std::endl;
}

void Appwrapper::displayClassMenu()
{
	for (int count = 1; count < (int)className::max; count++)
		std::cout << count << ". " << (className)count << std::endl;
}

void Appwrapper::displayPlayers()
{
	for (int count = 0; count < playerCount; count++)
			std::cout << "Player " << count+1 << ": Level " << playerSet[count][1].getLevel() << " " << playerSet[count][1].getClass() << std::endl;
}

void Appwrapper::displaySkillsMenu()
{
	for (int count = 0; count < (int)skillName::max; count++)
		std::cout << count << ". " << (skillName)count << std::endl;
}

void Appwrapper::displayAbilities()
{
	std::cout << "1. Strength" << std::endl << "2. Dexterity" << std::endl << "3. Constitution" << std::endl << "4. Intelligence" << std::endl << "5. Wisdom" << std::endl <<
		"6. Charisma" << std::endl;
}

void Appwrapper::displayTools()
{
	for (int count = 1; count < (int)toolName::max; count++)
		std::cout << count << ". " << (toolName)count << std::endl;
}