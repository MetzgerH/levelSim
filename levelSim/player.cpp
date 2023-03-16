#include "player.h"

void Player::initializeSkillSet()
{
	skillSet[(int)skillName::acrobatics]= Skill( abilityScore::dexterity);
	skillSet[(int)skillName::animalHandling] = Skill( abilityScore::wisdom);
	skillSet[(int)skillName::arcana] = Skill( abilityScore::intelligence);
	skillSet[(int)skillName::athletics] = Skill( abilityScore::strength);
	skillSet[(int)skillName::deception] = Skill(abilityScore::charisma);
	skillSet[(int)skillName::history] = Skill(abilityScore::intelligence);
	skillSet[(int)skillName::insight] = Skill(abilityScore::wisdom);
	skillSet[(int)skillName::intimidation] = Skill(abilityScore::charisma);
	skillSet[(int)skillName::investigation] = Skill(abilityScore::intelligence);
	skillSet[(int)skillName::medicine] = Skill(abilityScore::wisdom);
	skillSet[(int)skillName::nature] = Skill( abilityScore::intelligence);
	skillSet[(int)skillName::perception] = Skill(abilityScore::wisdom);
	skillSet[(int)skillName::performance] = Skill(abilityScore::charisma);
	skillSet[(int)skillName::persuasion] = Skill( abilityScore::charisma);
	skillSet[(int)skillName::religion] = Skill( abilityScore::intelligence);
	skillSet[(int)skillName::sleightOfHand] = Skill(abilityScore::dexterity);
	skillSet[(int)skillName::stealth] = Skill( abilityScore::dexterity);
	skillSet[(int)skillName::survival] = Skill(abilityScore::wisdom);

	saveSet[(int)abilityScore::strength] = Skill(abilityScore::strength);
	saveSet[(int)abilityScore::dexterity] = Skill(abilityScore::dexterity);
	saveSet[(int)abilityScore::constitution] = Skill(abilityScore::constitution);
	saveSet[(int)abilityScore::intelligence] = Skill(abilityScore::intelligence);
	saveSet[(int)abilityScore::wisdom] = Skill(abilityScore::wisdom);
	saveSet[(int)abilityScore::charisma] = Skill(abilityScore::charisma);
}

int Player::getSkillMod(skillName targetSkill)
{
	return this->getSkillMod(targetSkill, skillSet[(int)targetSkill].getAbility());
	/*if (skillSet[(int)targetSkill].isExpert())
		return 2 * proficiencyBonus + scoreToMod(abilities[(int)skillSet[(int)targetSkill].getAbility()]);
	if(skillSet[(int)targetSkill].isProficient())
		return proficiencyBonus + scoreToMod(abilities[(int)skillSet[(int)targetSkill].getAbility()]);
	return scoreToMod(abilities[(int)skillSet[(int)targetSkill].getAbility()]);*/
}

int Player::getSkillMod(skillName targetSkill, abilityScore targetAbility)
{
	
	if (skillSet[(int)targetSkill].isExpert())
		return 2 * proficiencyBonus + scoreToMod(abilities[(int)targetAbility]);
	if (skillSet[(int)targetSkill].isProficient())
		return proficiencyBonus + scoreToMod(abilities[(int)targetAbility]);
	return scoreToMod(abilities[(int)targetAbility]);
}

int Player::getSkillMod(skillName targetSkill, toolName targetTool)
{
	return this->getSkillMod(targetSkill, skillSet[(int)targetSkill].getAbility(), targetTool);
	/*int output = scoreToMod(abilities[(int)skillSet[(int)targetSkill].getAbility()]);
	if (skillSet[(int)targetSkill].isExpert())
		output+= 2 * proficiencyBonus;
	else if (skillSet[(int)targetSkill].isProficient())
		output+= proficiencyBonus;
	if (this->hasExpertise(targetTool))
		output += 2 * proficiencyBonus;
	else if (this->hasProficiency(targetTool))
		output += proficiencyBonus;
	return output;*/

}

int Player::getSkillMod(skillName targetSkill, abilityScore targetAbility, toolName targetTool)
{
	int output = this->getSkillMod(targetSkill, targetAbility);
	if (this->hasExpertise(targetTool))
		output += 2 * proficiencyBonus;
	else if (this->hasProficiency(targetTool))
		output += proficiencyBonus;
	return output;
}

int Player::getSaveMod(abilityScore targetSave)
{
	if (saveSet[(int)targetSave].isExpert())
		return 2 * proficiencyBonus + scoreToMod(abilities[(int)targetSave]);
	if (saveSet[(int)targetSave].isProficient())
		return proficiencyBonus + scoreToMod(abilities[(int)targetSave]);
	return scoreToMod(abilities[(int)targetSave]);
}

bool Player::hasProficiency(toolName targetTool)
{
	ToolNode* pCurrent = toolHead;
	while (pCurrent != nullptr)
	{
		if (pCurrent->getID() == targetTool)
			return true;
		pCurrent = pCurrent->getNext();
	}
	return false;
}

bool Player::hasExpertise(toolName targetTool)
{
	ToolNode* pCurrent = toolHead;
	while (pCurrent != nullptr)
	{
		if (pCurrent->getID() == targetTool && pCurrent->isExpert())
			return true;
		pCurrent =pCurrent->getNext();
	}
	return false;
}

int Player::getHealth()
{
	updateHealth();
	return maxHealth;
}

int Player::getLevel()
{
	return level;
}

void Player::updateHealth()
{
	maxHealth = healthFromRolls + level*scoreToMod(abilities[(int)abilityScore::constitution]);
}


void Player::levelUp()
{
	level++;
	healthFromRolls += d(hitDie);
	updateHealth();


	if (level == 4 || level == 8 || level == 12 || level == 16 || level == 19)
	{
		switch (coreClass)
		{
		case className::barbarian:
		{
			int weights[(int)abilityScore::max] = { 4, 2, 4, 1, 1, 1 };
			weightedASI(weights);
			break;
		}
		case className::bard:
		{
			int weights[(int)abilityScore::max] = { 1, 2, 1, 1, 4, 1 };
			weightedASI(weights);
			break;
		}
		case className::cleric:
		{
			int weights[(int)abilityScore::max] = { 3, 2, 3, 1, 6, 2 };
			weightedASI(weights);
			break;
		}
		case className::druid:
		{
			int weights[(int)abilityScore::max] = { 2, 2, 3, 1, 4, 1 };
			weightedASI(weights);
			break;
		}
		case className::fighter:
		{
			int weights[(int)abilityScore::max] = { 5, 2, 4, 1, 1, 1 };
			weightedASI(weights);
			break;
		}
		case className::monk:
		{
			int weights[(int)abilityScore::max] = { 1, 6, 4, 1, 4, 1 };
			weightedASI(weights);
			break;
		}
		case className::paladin:
		{
			int weights[(int)abilityScore::max] = { 4, 2, 3, 1, 7, 2 };
			weightedASI(weights);
			break;
		}
		case className::ranger:
		{
			int weights[(int)abilityScore::max] = { 2, 3, 2, 1, 4, 1 };
			weightedASI(weights);
			break;
		}
		case className::rogue:
		{
			int weights[(int)abilityScore::max] = { 1, 7, 4, 4, 2, 4 };
			weightedASI(weights);
			break;
		}
		case className::sorcerer:
		{
			int weights[(int)abilityScore::max] = { 1, 4, 3, 1, 1, 8 };
			weightedASI(weights);
			break;
		}
		case className::warlock:
		{
			int weights[(int)abilityScore::max] = { 2, 3, 3, 2, 2, 8 };
			weightedASI(weights);
			break;
		}
		case className::wizard:
		{
			int weights[(int)abilityScore::max] = { 1, 4, 3, 9, 3, 1 };
			weightedASI(weights);
			break;
		}
		}
	}

	switch (level)
	{
	case 5:
		proficiencyBonus = 3;
		break;
	case 9:
		proficiencyBonus = 4;
		break;
	case 13:
		proficiencyBonus = 5;
		break;
	case 17:
		proficiencyBonus = 6;
		break;
	}
}

int Player::gainProficiency(skillName targetSkill)
{
	
	if (this->hasProficiency(targetSkill))
		return 0;
	skillSet[(int)targetSkill].setProficiency(true);
	return 1;
}

bool Player::hasProficiency(skillName targetSkill)
{
	if (skillSet[(int)targetSkill].isProficient())
		return true;
	return false;
}

int Player::addSkillOutOf(skillName* options, int optionCount)
{
	int length = 0;
	skillName realOptions[(int)skillName::max] = {}; // this will have every skillName from options that isn't already proficient //the size is max-1, because that's how many skills there are
	for (int count = 0; count < optionCount; count++) //goes through every skill in options
	{
		if (!hasProficiency(options[count])) //checks if a skill is yet to be proficient
		{
			realOptions[length] = options[count]; //adds current skill to realOptions
			length++; //increments length of realOptions
		}
	}
	if (length == 0) //if length of realOptions==0, i.e. if we already have every skill
		return 0;

	int skillToAdd = d(length)-1;
	return this->gainProficiency(realOptions[skillToAdd]);
}

int Player::randExpertUpgrade()
{
	int length = 0;
	skillName options[(int)skillName::max] = {}; // this will have every skill that this player is proficient in, with a leading 0
	for (int count = 1; count < (int)skillName::max; count++)
	{
		if (!hasProficiency((skillName)count))
		{
			options[length] = (skillName)count;
			length++;
		}
	}
	if (length == 0)
		return 0;

	int skillToAdd = d(length);
	this->skillSet[skillToAdd].setExpertise(true);
	return 1;
}

int Player::setSaveProf(abilityScore targetSave, bool prof)
{
	if (saveSet[(int)targetSave].isProficient() == prof)
		return 0;
	saveSet[(int)targetSave].setProficiency(prof);
	return 1;
}

int Player::gainTool(toolName targetTool)
{
	if (toolHead == nullptr)
	{
		toolHead = new ToolNode(targetTool);
		return 1;
	}
	ToolNode* pCurrent = toolHead;
	while (pCurrent->getNext() != nullptr)
	{
		if (pCurrent->getID() == targetTool || pCurrent->getNext()->getID()==targetTool)
			return 0;
		pCurrent->setNext(pCurrent->getNext());
	}
	pCurrent->setNext(new ToolNode(targetTool));
	return 1;
}
void Player::gainTool()
{
	
	while (gainTool((toolName)d((int)toolName::max - 1)) == 0);
}

int Player::getProfBonus()
{
	return this->proficiencyBonus;
}

void Player::standardArray()
{
	int scores[6] = { 8,10,12,13,14,15 };
	int scoresLeft = 6;
	int abilityNum = 1;
	while (scoresLeft > 0)
	{
		int slot = d(scoresLeft)-1;
		abilities[abilityNum] = scores[slot];
		abilityNum++;
		while (slot+1 < scoresLeft)
		{
			scores[slot] = scores[slot+1];
			slot++;
		}
		scoresLeft--;
	}
}

void Player::standardArray(abilityScore priority)
{
	int scores[6] = { 8,10,12,13,14,15 };
	int scoresLeft = 6;
	int slot = d(scoresLeft)-1;
	int slot2 = d(scoresLeft)-1;
	int slot3 = d(scoresLeft) - 1;
	if (slot2 > slot)
		slot = slot2;
	if (slot3 > slot)
		slot = slot3;
	abilities[(int)priority] = scores[slot];
	while (slot + 1 < scoresLeft) //iterate through the rest of the array
	{
		scores[slot] = scores[slot+1]; //replace current spot with next spot; current spot will either be the score just taken, or duplicated by the last run of this
		slot++;
	}
	scoresLeft--;


	int abilityNum = 1;
	while (scoresLeft > 0)
	{
		if (abilityNum == (int)priority)
			abilityNum++;
		slot = rand() % scoresLeft;
		abilities[abilityNum] = scores[slot];
		abilityNum++;
		while (slot + 1 < scoresLeft)
		{
			scores[slot] = scores[slot+1];
			slot++;
		}
		scoresLeft--;
	}
}

void Player::standardArray(abilityScore priority1, abilityScore priority2)
{
	int scores[6] = { 8,10,12,13,14,15 };
	int scoresLeft = 6;
	int slot = d(scoresLeft)-1;
	int slot2 = d(scoresLeft)-1;
	int slot3 = d(scoresLeft) - 1;
	if (slot2 > slot)
		slot = slot2;
	if (slot3 > slot)
		slot = slot3;
	abilities[(int)priority1] = scores[slot];
	while (slot + 1 < scoresLeft)
	{
		scores[slot] = scores[slot+1];
		slot++;
	}
	scoresLeft--;

	slot = d(scoresLeft)-1;
	slot2 = d(scoresLeft)-1;
	if (slot2 > slot)
		slot = slot2;
	abilities[(int)priority2] = scores[slot];
	while (slot + 1 < scoresLeft)
	{
		scores[slot] = scores[slot+1];
		slot++;
	}
	scoresLeft--;

	int abilityNum = 1;
	while (scoresLeft > 0)
	{
		while (abilityNum == (int)priority1 || abilityNum == (int)priority2)
			abilityNum++;
		slot = d(scoresLeft)-1;
		abilities[abilityNum] = scores[slot];
		abilityNum++;
		while (slot + 1 < scoresLeft)
		{
			scores[slot] = scores[slot+1];
			slot++;
		}
		scoresLeft--;
	}
}

void Player::standardArray(abilityScore priority1, abilityScore priority2, abilityScore priority3)
{
	int scores[6] = { 8,10,12,13,14,15 };
	int scoresLeft = 6;
	int slot = d(scoresLeft)-1;
	int slot2 = d(scoresLeft)-1;
	int slot3 = d(scoresLeft) - 1;
	if (slot2 > slot)
		slot = slot2;
	if (slot3 > slot)
		slot = slot3;
	abilities[(int)priority1] = scores[slot];
	while (slot + 1 < scoresLeft)
	{
		scores[slot] = scores[slot+1];
		slot++;
	}
	scoresLeft--;

	slot = d(scoresLeft)-1;
	slot2 = d(scoresLeft)-1;
	if (slot2 > slot)
		slot = slot2;
	abilities[(int)priority2] = scores[slot];
	while (slot + 1 < scoresLeft)
	{
		scores[slot] = scores[slot+1];
		slot++;
	}
	scoresLeft--;

	slot = d(scoresLeft)-1;
	slot2 = d(scoresLeft)-1;
	if (slot2 > slot)
		slot = slot2;
	abilities[(int)priority3] = scores[slot];
	while (slot + 1 < scoresLeft)
	{
		scores[slot] = scores[slot+1];
		slot++;
	}
	scoresLeft--;

	int abilityNum = 1;
	while (scoresLeft > 0)
	{
		while (abilityNum == (int)priority1 || abilityNum == (int)priority2 || abilityNum == (int)priority3)
			abilityNum++;
		slot = d(scoresLeft)-1;
		abilities[abilityNum] = scores[slot];
		abilityNum++;
		while (slot + 1 < scoresLeft)
		{
			scores[slot] = scores[slot+1];
			slot++;
		}
		scoresLeft--;
	}
}

void Player::randomASI()
{
	int randy = d(2);
	if (randy == 1) //we only do +1 increases half the time
	{
		for (int count = 0; count < 2; count++)
		{
			randy = d(6);
			if (abilities[randy] < 20) //check if this stat is maxed out
				abilities[randy]++;//sometimes this rolls the same thing twice in a row, I'm okay with that because +2's are more popular anyways
			else
				count--;
		}
	}
	else
	{
		randy = d(6);
		if (abilities[randy] < 19) //check if this stat is maxed out
		{
			abilities[randy]++;
			abilities[randy]++;
		}
		else
			this->randomASI();
	}
}

void Player::weightedASI(int weights[(int)abilityScore::max])
{
	int totalWeight = 0;
	for (int count = 1; count < 7; count++)
	{
		totalWeight += weights[count];
	}
	if (totalWeight < 1)
		return;
	int isSeparate = 0;
	if (this->rng != nullptr)
		isSeparate = (*rng)() % 2;
	else
		isSeparate = rand() % 2;
	if (isSeparate == 0)
	{
		int randy = 0;
		for (int iteration = 0; iteration < 2; iteration++) // two +1's
		{
			randy = d(totalWeight);
			for (int count = 1; count < 7; count++)
			{
				randy -= weights[count];
				if (randy <= 0)
				{
					if (abilities[count] < 20)
						abilities[count]++;
					else
						iteration--;
					count = 7; //end loop
				}
			}
		}
	}
	else //one +2
	{
		int randy = d(totalWeight);
		for (int count = 1; count < 7; count++)
		{
			randy -= weights[count];
			if (randy <= 0)
			{
				if (abilities[count] < 19)//check if this ability is maxed out
				{
					abilities[count]++;
					abilities[count]++;
				}
				else
					this->randomASI();
				count = 7; //end loop
			}
		}
	}
}

void Player::randomCustomLineage()
{
	skillName skillOptions[(int)skillName::max] = {  };
	for (int count = 1; count < (int)skillName::max; count++) // every skill
	{
		skillOptions[count] = (skillName)count;
	}
	this->addSkillOutOf(skillOptions, (int)skillName::max-1);
	randomASI();
	//randomFeat(); //to be implemented (maybe)
	//randomLang(); //to be imlpemented (maybe)
}

void Player::setRNG(std::mt19937* newRNG)
{
	this->rng = newRNG;
}

int Player::d(int dieSize)
{
	int output = 0;
	if (this->rng != nullptr)
		output = (*rng)() % dieSize + 1;
	else
		output = rand() % dieSize + 1;
	return output;
}

void Player::setAbility(abilityScore targetAbility, int newScore)
{
	abilities[(int)targetAbility] = newScore;
}

int Player::getAbility(abilityScore targetAbility)
{
	return abilities[(int)targetAbility];
}

int Player::getInitiative()
{
	return abilities[(int)abilityScore::dexterity];
}

//this addBackground() uses 5e rules instead of OneD&D rules
#ifndef ONEDND
void Player::addBackground(background newBackground)
{
	
	switch (newBackground)
	{
	case background::acolyte:
		this->gainProficiency(skillName::insight);
		this->gainProficiency(skillName::religion);
		//this->gainLanguage();
		//this->gainLanguage();
		break;
	case background::charlatan:
		this->gainProficiency(skillName::deception);
		this->gainProficiency(skillName::sleightOfHand);
		this->gainTool(toolName::disguise);
		this->gainTool(toolName::forgery);
		break;
	case background::criminal:
		this->gainProficiency(skillName::deception);
		this->gainProficiency(skillName::stealth);
		this->gainTool(toolName::thieves);
		this->gainTool(toolName::gaming);
		break;
	case background::entertainer:
		this->gainProficiency(skillName::acrobatics);
		this->gainProficiency(skillName::performance);
		this->gainTool(toolName::disguise);
		this->gainTool(toolName::instrument);
		break;
	case background::folkHero:
		this->gainProficiency(skillName::animalHandling);
		this->gainProficiency(skillName::survival);
		this->gainTool();
		this->gainTool(toolName::landVehicles);
		break;
	case background::guildArtisan:
		this->gainProficiency(skillName::insight);
		this->gainProficiency(skillName::persuasion);
		this->gainTool();
		//this->gainLanguage();
		break;
	case background::hermit:
		this->gainProficiency(skillName::medicine);
		this->gainProficiency(skillName::religion);
		this->gainTool(toolName::herbalism);
		//this->gainLanguage();
		break;
	case background::noble:
		this->gainProficiency(skillName::history);
		this->gainProficiency(skillName::persuasion);
		this->gainTool(toolName::gaming);
		//this->gainLanguage();
		break;
	case background::outlander:
		this->gainProficiency(skillName::athletics);
		this->gainProficiency(skillName::survival);
		this->gainTool(toolName::instrument);
		//this->gainLanguage();
		break;
	case background::sailor:
		this->gainProficiency(skillName::athletics);
		this->gainProficiency(skillName::perception);
		this->gainTool(toolName::navigators);
		this->gainTool(toolName::waterVehicles);
		break;
	case background::soldier:
		this->gainProficiency(skillName::athletics);
		this->gainProficiency(skillName::intimidation);
		this->gainTool(toolName::gaming);
		this->gainTool(toolName::landVehicles);
		break;
	case background::urchin:
		this->gainProficiency(skillName::sleightOfHand);
		this->gainProficiency(skillName::stealth);
		this->gainTool(toolName::disguise);
		this->gainTool(toolName::thieves);
		break;
	}
}
#endif

#ifdef ONEDND
void Player::addBackground(background newBackground)
{
	switch (newBackground)
	{
	case background::acolyte:
		abilities[(int)abilityScore::wisdom]+=2;
		abilities[(int)abilityScore::intelligence]++;
		this->gainProficiency(skillName::insight);
		this->gainProficiency(skillName::religion);
		this->gainTool(toolName::calligraphers);
		break;
	case background::artisan:
		abilities[(int)abilityScore::intelligence] += 2;
		abilities[(int)abilityScore::charisma]++;
		this->gainProficiency(skillName::investigation);
		this->gainProficiency(skillName::persuasion);
		this->gainTool();
		break;
	case background::charlatan:
		abilities[(int)abilityScore::charisma] += 2;
		abilities[(int)abilityScore::dexterity]++;
		this->gainProficiency(skillName::investigation);
		this->gainProficiency(skillName::persuasion);
		this->gainTool();
		break;
	case background::criminal:
		abilities[(int)abilityScore::dexterity] += 2;
		abilities[(int)abilityScore::intelligence]++;
		this->gainProficiency(skillName::sleightOfHand);
		this->gainProficiency(skillName::stealth);
		this->gainTool(toolName::thieves);
		break;
	case background::cultist:
		abilities[(int)abilityScore::intelligence] += 2;
		abilities[(int)abilityScore::charisma]++;
		this->gainProficiency(skillName::arcana);
		this->gainProficiency(skillName::religion);
		this->gainTool(toolName::disguise);
		break;
	case background::entertainer:
		abilities[(int)abilityScore::charisma] += 2;
		abilities[(int)abilityScore::dexterity]++;
		this->gainProficiency(skillName::acrobatics);
		this->gainProficiency(skillName::performance);
		this->gainTool(toolName::instrument);
		break;
	case background::farmer:
		abilities[(int)abilityScore::constitution] += 2;
		abilities[(int)abilityScore::wisdom]++;
		this->gainProficiency(skillName::animalHandling);
		this->gainProficiency(skillName::nature);
		this->gainTool(toolName::carpenters);
		break;
	case background::gladiator:
		abilities[(int)abilityScore::strength] += 2;
		abilities[(int)abilityScore::charisma]++;
		this->gainProficiency(skillName::athletics);
		this->gainProficiency(skillName::performance);
		this->gainTool(toolName::smiths);
		break;
	case background::guard:
		abilities[(int)abilityScore::strength] += 2;
		abilities[(int)abilityScore::wisdom]++;
		this->gainProficiency(skillName::athletics);
		this->gainProficiency(skillName::perception);
		this->gainTool(toolName::gaming);
		break;
	case background::guide:
		abilities[(int)abilityScore::wisdom] += 2;
		abilities[(int)abilityScore::dexterity]++;
		this->gainProficiency(skillName::stealth);
		this->gainProficiency(skillName::survival);
		this->gainTool(toolName::cartographers);
		break;
	case background::hermit:
		abilities[(int)abilityScore::wisdom] += 2;
		abilities[(int)abilityScore::constitution]++;
		this->gainProficiency(skillName::medicine);
		this->gainProficiency(skillName::religion);
		this->gainTool(toolName::herbalism);
		break;
	case background::laborer:
		abilities[(int)abilityScore::constitution] += 2;
		abilities[(int)abilityScore::strength]++;
		this->gainProficiency(skillName::athletics);
		this->gainProficiency(skillName::survival);
		this->gainTool(toolName::masons);
		break;
	case background::noble:
		abilities[(int)abilityScore::charisma] += 2;
		abilities[(int)abilityScore::intelligence]++;
		this->gainProficiency(skillName::history);
		this->gainProficiency(skillName::persuasion);
		this->gainTool(toolName::gaming);
		break;
	case background::pilgrim:
		abilities[(int)abilityScore::wisdom] += 2;
		abilities[(int)abilityScore::constitution]++;
		this->gainProficiency(skillName::religion);
		this->gainProficiency(skillName::survival);
		this->gainTool(toolName::instrument);
		break;
	case background::sage:
		abilities[(int)abilityScore::intelligence] += 2;
		abilities[(int)abilityScore::wisdom]++;
		this->gainProficiency(skillName::arcana);
		this->gainProficiency(skillName::history);
		this->gainTool(toolName::calligraphers);
		break;
	case background::sailor:
		abilities[(int)abilityScore::dexterity] += 2;
		abilities[(int)abilityScore::wisdom]++;
		this->gainProficiency(skillName::acrobatics);
		this->gainProficiency(skillName::perception);
		this->gainTool(toolName::navigators);
		break;
	case background::soldier:
		abilities[(int)abilityScore::strength] += 2;
		abilities[(int)abilityScore::constitution]++;
		this->gainProficiency(skillName::athletics);
		this->gainProficiency(skillName::intimidation);
		this->gainTool(toolName::gaming);
		break;
	case background::urchin:
		abilities[(int)abilityScore::dexterity] += 2;
		abilities[(int)abilityScore::wisdom]++;
		this->gainProficiency(skillName::insight);
		this->gainProficiency(skillName::stealth);
		this->gainTool(toolName::thieves);
		break;
	}
}
#endif

void Player::addBackground()
{
	int backgroundToGain = d((int)background::max - 1);
	this->addBackground((background)backgroundToGain);
}

void Player::pickSkillsRandomly()
{
	switch (coreClass)
	{
	case className::barbarian:
	{
		skillName skillOptions[6] = { skillName::animalHandling, skillName::athletics, skillName::intimidation, skillName::nature, skillName::perception, skillName::survival };
		this->addSkillOutOf(skillOptions, 6);
		this->addSkillOutOf(skillOptions, 6);
		break;
	}

	case className::bard:
	{
		skillName skillOptions[(int)skillName::max] = {  };
		for (int count = 0; count < (int)skillName::max; count++) //bard's list includes every single skill so we do just cycle through all of them
		{
			skillOptions[count] = (skillName)(count + 1);
		}
		this->addSkillOutOf(skillOptions, (int)skillName::max);
		this->addSkillOutOf(skillOptions, (int)skillName::max);
		this->addSkillOutOf(skillOptions, (int)skillName::max);
		break;
	}

	case className::cleric:
	{
		skillName skillOptions[5] = { skillName::history, skillName::insight, skillName::medicine, skillName::persuasion, skillName::religion };
		this->addSkillOutOf(skillOptions, 5);
		this->addSkillOutOf(skillOptions, 5);
		break;
	}
	case className::druid:
	{
		skillName skillOptions[8] = { skillName::arcana, skillName::animalHandling, skillName::insight, skillName::medicine, skillName::nature, skillName::perception,
			skillName::religion, skillName::survival };
		this->addSkillOutOf(skillOptions, 8);
		this->addSkillOutOf(skillOptions, 8);
		break;
	}
	case className::fighter:
	{
		skillName skillOptions[8] = { skillName::acrobatics, skillName::animalHandling, skillName::athletics, skillName::history, skillName::insight, skillName::intimidation,
			skillName::perception, skillName::survival };
		this->addSkillOutOf(skillOptions, 8);
		this->addSkillOutOf(skillOptions, 8);
		break;
	}
	case className::monk:
	{
		skillName skillOptions[6] = { skillName::acrobatics, skillName::athletics, skillName::history, skillName::insight, skillName::religion, skillName::stealth };
		this->addSkillOutOf(skillOptions, 6);
		this->addSkillOutOf(skillOptions, 6);
		break;
	}
	case className::paladin:
	{
		skillName skillOptions[6] = { skillName::athletics, skillName::insight, skillName::intimidation, skillName::medicine, skillName::persuasion, skillName::religion };
		this->addSkillOutOf(skillOptions, 6);
		this->addSkillOutOf(skillOptions, 6);
		break;
	}
	case className::ranger:
	{
		skillName skillOptions[8] = { skillName::animalHandling, skillName::athletics, skillName::insight, skillName::investigation, skillName::nature, skillName::perception,
			skillName::stealth, skillName::survival };
		this->addSkillOutOf(skillOptions, 8);
		this->addSkillOutOf(skillOptions, 8);
		this->addSkillOutOf(skillOptions, 8);
		break;
	}
	case className::rogue:
	{
		skillName skillOptions[11] = { skillName::acrobatics, skillName::athletics, skillName::deception, skillName::insight, skillName::intimidation, skillName::investigation,
			skillName::perception, skillName::performance, skillName::persuasion, skillName::sleightOfHand, skillName::stealth };
		this->addSkillOutOf(skillOptions, 11);
		this->addSkillOutOf(skillOptions, 11);
		this->addSkillOutOf(skillOptions, 11);
		this->addSkillOutOf(skillOptions, 11);

		this->randExpertUpgrade();
		this->randExpertUpgrade();
		break;
	}
	case className::sorcerer:
	{
		skillName skillOptions[6] = { skillName::arcana, skillName::deception, skillName::insight, skillName::intimidation, skillName::persuasion, skillName::religion };
		this->addSkillOutOf(skillOptions, 6);
		this->addSkillOutOf(skillOptions, 6);
		break;
	}
	case className::warlock:
	{
		skillName skillOptions[6] = { skillName::arcana, skillName::deception, skillName::history, skillName::intimidation, skillName::nature, skillName::religion };
		this->addSkillOutOf(skillOptions, 6);
		this->addSkillOutOf(skillOptions, 6);
		break;
	}
	case className::wizard:
	{
		skillName skillOptions[6] = { skillName::arcana, skillName::history, skillName::insight, skillName::investigation, skillName::medicine, skillName::religion };
		this->addSkillOutOf(skillOptions, 6);
		this->addSkillOutOf(skillOptions, 6);
		break;
	}
	}
}

className Player::getClass()
{
	return coreClass;
}


std::ostream& operator<<(std::ostream& lhs, className rhs)
{
	return lhs << toString(rhs);
}

std::string toString(className input)
{
	switch (input)
	{
	case className::barbarian:
		return "barbarian";
	case className::bard:
		return "bard";
	case className::cleric:
		return "cleric";
	case className::druid:
		return "druid";
	case className::fighter:
		return "fighter";
	case className::monk:
		return "monk";
	case className::paladin:
		return "paladin";
	case className::ranger:
		return "ranger";
	case className::rogue:
		return "rogue";
	case className::sorcerer:
		return "sorcerer";
	case className::warlock:
		return "warlock";
	case className::wizard:
		return "wizard";
	}
}