#pragma once

#include <iostream>

enum class abilityScore :char //we inherit from char for memory reasons
{
	strength=1, dexterity, constitution, intelligence, wisdom, charisma, max
};

enum class skillName : char //we inherit from char for memory reasons
{
	acrobatics, animalHandling, arcana, athletics, deception, history, insight, intimidation, investigation, medicine, nature, perception, performance, persuasion, 
	religion, sleightOfHand, stealth, survival, max
};



class Skill //this also works with saving throws
{
private:
	//skillName name;
	abilityScore associatedAbility;
	bool proficient;
	bool expertise;
public:
	Skill(/*skillName newName,*/ abilityScore ability, bool isProf, bool isExpert);
	Skill(/*skillName newName,*/ abilityScore ability, bool isProf);
	Skill(/*skillName newName,*/ abilityScore ability);
	//Skill(abilityScore ability); //this is for saves
	Skill();
	/*skillName getName();
	void setName(skillName newName);*/
	bool isProficient();
	void setProficiency(bool prof);
	bool isExpert();
	void setExpertise(bool expert);
	abilityScore getAbility();
};



int scoreToMod(int score);

std::ostream& operator<< (std::ostream& lhs, skillName rhs);

std::ostream& operator<< (std::ostream& lhs, abilityScore rhs);