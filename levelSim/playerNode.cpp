#include "playerNode.h"

PlayerNode::~PlayerNode()
{
	delete pData; //this is a shallow destructor
	pData = nullptr;
}

Player* PlayerNode::getData()
{
	return pData;
}

void PlayerNode::setData(Player* newData)
{
	pData = newData;
}

PlayerNode* PlayerNode::getNext()
{
	return pNext;
}

void PlayerNode::setNext(PlayerNode* newNext)
{
	pNext = newNext;
}