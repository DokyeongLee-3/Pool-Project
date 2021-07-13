#pragma once
#include <memory>
#include <iostream>
#include "..\BlockUnit\CBlockUnit.h"
#include "..\MemoryBlock\CMemoryBlock.h"


class CPoolManager
{
private:
	std::unique_ptr<CMemoryBlock> MemoryBlockHandle;

	// CMemoryBlock::Allocate�κ��� �Ҵ���� �޸� chunk(arena_size�� ũ��)
	CBlockUnit* m_MemoryChunk;

	size_t m_ArenaSize;

public:
	CPoolManager(size_t arena_size);
	~CPoolManager();

	void* Allocate(size_t size);
	void Deallocate(void* mem);


};

