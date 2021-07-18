#pragma once
//#include <stack>
#include <vector>
#include "..\CObject.h"


class CObjectPoolManager
{
private:
	int m_InitObjectCount;
	//std::stack<CObject*> m_ObjectStack;
	std::vector<CObject*> m_ObjectVector;


public:
	CObjectPoolManager(int count);
	~CObjectPoolManager();

public:
	CObject* Allocate();
	void Deallocate(CObject* obj);
};

