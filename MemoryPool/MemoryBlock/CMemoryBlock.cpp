#include "CMemoryBlock.h"
#include <iostream>
#include <algorithm>

CMemoryBlock::CMemoryBlock(size_t arena_size) : m_UnitSize(0), m_ArenaSize(arena_size)
{
	/*
	char* p = new char[arena_size];
	m_BlockStart = p;
	m_FreeBlock = reinterpret_cast<CBlockUnit*>(p);
	*/
	
	char* p = (char*)malloc(arena_size);
	m_BlockStart = p;
	m_FreeBlock = reinterpret_cast<CBlockUnit*>(p);
	
}

CMemoryBlock::~CMemoryBlock()
{
	//delete[] m_BlockStart;
	free(m_BlockStart);
}

void* CMemoryBlock::Allocate(size_t size)
{
	// Is it required?
	// size = std::max(size, sizeof(void*));

	if (m_UnitSize == 0)
	{
		m_UnitSize = size;
	}
	// arena_size 넘게 Allocate하려고 하면 여기 블록으로 진입
	// 이전에 CMemoryBlock::Allocate가 불렸는데 또 불리고, m_FreeBlock이 nullptr이다 -> arena_size만큼 모두 소진
	else
	{
		if (m_FreeBlock == nullptr)
		{
			throw std::bad_alloc();
		}
	}

	int count = GetCount();

	auto ret = m_FreeBlock;

	for (int i = 0; i < count; ++i)
	{
		auto p = reinterpret_cast<char*>(m_FreeBlock) + size;
		if (i != count - 1)
		{
			m_FreeBlock->setNext(p);
		}
		else
		{
			m_FreeBlock->setNext(nullptr);
		}
		m_FreeBlock = m_FreeBlock->GetNext();
	}

	return ret;
}

void CMemoryBlock::Deallocate(void* mem)
{
	/*
	if (!mem)
	{
		m_FreeBlock->setNext(m_FreeBlock);
		m_FreeBlock = reinterpret_cast<CBlockUnit*>(mem);
	}
	*/
}

int CMemoryBlock::GetCount()
{

	return m_ArenaSize/m_UnitSize;
}

size_t CMemoryBlock::GetArenaSize()
{
	return m_ArenaSize;
}

size_t CMemoryBlock::GetUnitSize()
{
	return m_UnitSize;
}

void* CMemoryBlock::GetBlockStart()
{
	return m_BlockStart;
}
