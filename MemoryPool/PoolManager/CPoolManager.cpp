#include "CPoolManager.h"

CPoolManager::CPoolManager(size_t arena_size) : m_ArenaSize(arena_size)
{
	MemoryBlockHandle = std::make_unique<CMemoryBlock>(arena_size);
}

CPoolManager::~CPoolManager()
{

}

void* CPoolManager::Allocate(size_t size)
{	
	try
	{
		if (size < 0)
		{
			throw std::bad_alloc();
		}

		if (!m_MemoryChunk)
		{
			m_MemoryChunk = reinterpret_cast<CBlockUnit*>(MemoryBlockHandle->Allocate(size));
		}

		// CMemoryBlock::Allocate가 호출돼서 여기로 점프하는건 맨처음 Allocate 호출된 경우이거나(정상)
		// 처음 Allocate한거 보다 더 큰 사이즈를 Allocate하려거나(고정 메모리 블록 방식이므로 예외처리)
		if (MemoryBlockHandle->GetUnitSize() < size)
		{
			throw std::bad_alloc();
		}
	}

	catch (const std::bad_alloc& bad)
	{
		std::cout << "bad allocation" << std::endl;
		exit(1);
	}

	auto ret = m_MemoryChunk;
	m_MemoryChunk = m_MemoryChunk->GetNext();


	return ret;
}

void CPoolManager::Deallocate(void* mem)
{
	// 굳이 MemoryBlockHandle 이용안하고 갖고 있는 멤버 MemoryChunk 이용해서 Deallocate 가능
	//MemoryBlockHandle->Deallocate(mem);
	if (mem)
	{
		auto p = m_MemoryChunk;

		m_MemoryChunk = reinterpret_cast<CBlockUnit*>(mem);
		m_MemoryChunk->setNext(p);
	}
}
