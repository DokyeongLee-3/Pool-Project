#pragma once
#include "..\BlockUnit\CBlockUnit.h"

class CMemoryBlock
{
private:
	void* m_BlockStart;
	size_t m_ArenaSize;
	// 맨 처음 Allocate를 이용해서 할당한 사이즈로 계속 할당해야 하는데(고정 메모리블록 방식이므로)
	// 나중에 더 큰 사이즈를 Allocate하려 한다면 bad_alloc 예외처리
	size_t m_UnitSize;
	CBlockUnit* m_FreeBlock;


public:
	CMemoryBlock(size_t arena_size);
	~CMemoryBlock();

public:
	void* Allocate(size_t size);
	void Deallocate(void* mem);

public:
	int GetCount();
	size_t GetArenaSize();
	size_t GetUnitSize();
	void* GetBlockStart();

	
};

