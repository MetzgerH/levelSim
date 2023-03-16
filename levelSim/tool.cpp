#include "tool.h"

bool ToolNode::isExpert()
{
	return expertise;
}
void ToolNode::setExpertise(bool newExpert)
{
	expertise = newExpert;
}
toolName ToolNode::getID()
{
	return identifier;
}

ToolNode* ToolNode::getNext()
{
	return pNext;
}
void ToolNode::setNext(ToolNode* newNext)
{
	pNext = newNext;
}


std::ostream& operator<< (std::ostream& lhs, toolName rhs)
{
	
	switch (rhs)
	{
	case toolName::alchemists:
		return lhs << "alchemist's supplies";
	case toolName::brewers:
		return lhs << "brewer's supplies";
	case toolName::calligraphers:
		return lhs << "calligrapher's supplies";
	case toolName::carpenters:
		return lhs << "carpenter's tools";
	case toolName::cartographers:
		return lhs << "cartographer's tools";
	case toolName::cobblers:
		return lhs << "cobbler's tools";
	case toolName::cooks:
		return lhs << "cook's utensils";
	case toolName::disguise:
		return lhs << "disguise kit";
	case toolName::forgery:
		return lhs << "forgery kit";
	case toolName::gaming:
		return lhs << "a gaming set";
	case toolName::glassblowers:
		return lhs << "glassblower's tools";
	case toolName::herbalism:
		return lhs << "herbalism kit";
	case toolName::jewelers:
		return lhs << "jeweler's tools";
	case toolName::landVehicles:
		return lhs << "vehicles (land)";
	case toolName::waterVehicles:
		return lhs << "vehicles (water)";
	case toolName::leatherworkers:
		return lhs << "leatherworker's tools";
	case toolName::masons:
		return lhs << "mason's tools";
	case toolName::instrument:
		return lhs << "a musical instrument";
	case toolName::navigators:
		return lhs << "navigator's tools";
	case toolName::painters:
		return lhs << "painter's supplies";
	case toolName::poisoners:
		return lhs << "poisoner's kit";
	case toolName::potters:
		return lhs << "potter's tools";
	case toolName::smiths:
		return lhs << "smith's tools";
	case toolName::thieves:
		return lhs << "thieves' tools";
	case toolName::tinkers:
		return lhs << "tinker's tools";
	case toolName::weavers:
		return lhs << "weaver's tools";
	case toolName::woodcarvers:
		return lhs << "woodcarver's tools";
	}
}
