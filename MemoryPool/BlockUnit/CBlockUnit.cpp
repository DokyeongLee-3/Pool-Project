#include "CBlockUnit.h"

CBlockUnit::CBlockUnit() : m_Next(nullptr)
{
}

CBlockUnit::~CBlockUnit()
{
}

void CBlockUnit::setNext(void* next)
{
	m_Next = reinterpret_cast<CBlockUnit*>(next);
}

CBlockUnit* CBlockUnit::GetNext()
{
	return m_Next;
}
