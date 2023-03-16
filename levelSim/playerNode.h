#pragma once

#include "classes.h"

class PlayerNode
{
private:
	PlayerNode* pNext;
	Player* pData;
public:
	PlayerNode()
	{
		pNext = nullptr;
		pData = nullptr;
	}
	PlayerNode(Player* newData)
	{
		pNext = nullptr;
		pData = newData;
	}
	~PlayerNode();
	Player* getData();
	void setData(Player*);
	PlayerNode* getNext();
	void setNext(PlayerNode* newNext);
};