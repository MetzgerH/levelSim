#pragma once

#include <iostream>

enum class toolName : char
{
	alchemists = 1, brewers, calligraphers, carpenters, cartographers, cobblers, cooks, disguise, forgery, gaming, glassblowers, herbalism, jewelers, landVehicles, waterVehicles, leatherworkers,
	masons, instrument, navigators, painters, poisoners, potters, smiths, thieves, tinkers, weavers, woodcarvers, max
};

class ToolNode
{
private:
	ToolNode* pNext;
	toolName identifier;
	bool expertise;
public:
	ToolNode(toolName name = (toolName)0, bool isExpert = false)
	{
		pNext = 0;
		identifier = name;
		expertise = isExpert;
	}
	bool isExpert();
	void setExpertise(bool newExpert = true);
	ToolNode* getNext();
	void setNext(ToolNode* newNext);
	toolName getID();
};

std::ostream& operator<< (std::ostream& lhs, toolName rhs);