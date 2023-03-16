#include "skill.h"

Skill::Skill(/*skillName newName,*/ abilityScore ability, bool isProf, bool isExpert)
{
	/*this->name = newName;*/
	this->associatedAbility = ability;
	this->proficient = isProf;
	this->expertise = isExpert;
}
Skill::Skill(/*skillName newName,*/ abilityScore ability, bool isProf)
{
	/*this->name = newName;*/
	this->associatedAbility = ability;
	this->proficient = isProf;
	this->expertise = false;
}
Skill::Skill(/*skillName newName,*/ abilityScore ability)
{
	/*this->name = newName;*/
	this->associatedAbility = ability;
	this->proficient = false;
	this->expertise = false;
}
//Skill::Skill(abilityScore ability)
//{
//	//this->name = (skillName)0;
//	this->associatedAbility = ability;d
//	this->proficient = false;
//	this->expertise = false;
//}
Skill::Skill()
{
	//this->name = (skillName)0;
	this->associatedAbility = (abilityScore)0;
	this->proficient = false;
	this->expertise = false;
}

//skillName Skill::getName()
//{
//	return this->name;
//}
//void Skill::setName(skillName newName)
//{
//	this->name = newName;
//}

bool Skill::isProficient()
{
	return this->proficient;
}

bool Skill::isExpert()
{
	return this->expertise;
}

abilityScore Skill::getAbility()
{
	return associatedAbility;
}

void Skill::setProficiency(bool prof)
{
	proficient = prof;
}

void Skill::setExpertise(bool expert)
{
	expertise = expert;
}


int scoreToMod(int score)
{
	return (score / 2) - 5;
}


std::ostream& operator<< (std::ostream& lhs, skillName rhs)
{
	switch (rhs)
	{
	case skillName::acrobatics:
		return lhs << "acrobatics";
	case skillName::animalHandling:
		return lhs << "animal handling";
	case skillName::arcana:
		return lhs << "arcana";
	case skillName::athletics:
		return lhs << "athletics";
	case skillName::deception :
		return lhs << "deception";
	case skillName::history:
		return lhs << "history";
	case skillName::insight:
		return lhs << "insight";
	case skillName::intimidation:
		return lhs << "intimidation";
	case skillName::investigation:
		return lhs << "investigation";
	case skillName::medicine:
		return lhs << "medicine";
	case skillName::nature:
		return lhs << "nature";
	case skillName::perception:
		return lhs << "perception";
	case skillName::performance:
		return lhs << "performance";
	case skillName::persuasion:
		return lhs << "persuasion";
	case skillName::religion:
		return lhs << "religion";
	case skillName::sleightOfHand:
		return lhs << "sleight of hand";
	case skillName::stealth:
		return lhs << "stealth";
	case skillName::survival:
		return lhs << "survival";
	default:
		return lhs;
	}
}

std::ostream& operator<< (std::ostream& lhs, abilityScore rhs)
{
	switch (rhs)
	{
	case abilityScore::strength:
		return lhs << "Strength";
	case abilityScore::dexterity:
		return lhs << "Dexterity";
	case abilityScore::constitution:
		return lhs << "Constitution";
	case abilityScore::charisma:
		return lhs << "Charisma";
	case abilityScore::intelligence:
		return lhs << "Intelligence";
	case abilityScore::wisdom:
		return lhs << "Wisdom";
	default:
		return lhs;
	}
}