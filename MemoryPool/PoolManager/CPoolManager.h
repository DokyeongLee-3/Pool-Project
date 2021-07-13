#pragma once
#include <memory>
#include <iostream>
#include "..\BlockUnit\CBlockUnit.h"
#include "..\MemoryBlock\CMemoryBlock.h"


class CPoolManager
{
private:
	std::unique_ptr<CMemoryBlock> MemoryBlockHandle;

	// CMemoryBlock::Allocate로부터 할당받은 메모리 chunk(arena_size의 크기)
	CBlockUnit* m_MemoryChunk;

	size_t m_ArenaSize;

public:
	CPoolManager(size_t arena_size);
	~CPoolManager();

	void* Allocate(size_t size);
	void Deallocate(void* mem);


};

