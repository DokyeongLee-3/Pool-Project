#pragma once
class CBlockUnit
{
	CBlockUnit* m_Next;
	
public:
	CBlockUnit();
	~CBlockUnit();

public:
	void setNext(void* next);
	CBlockUnit* GetNext();
};

