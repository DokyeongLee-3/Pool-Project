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

		// CMemoryBlock::Allocate�� ȣ��ż� ����� �����ϴ°� ��ó�� Allocate ȣ��� ����̰ų�(����)
		// ó�� Allocate�Ѱ� ���� �� ū ����� Allocate�Ϸ��ų�(���� �޸� ��� ����̹Ƿ� ����ó��)
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
	// ���� MemoryBlockHandle �̿���ϰ� ���� �ִ� ��� MemoryChunk �̿��ؼ� Deallocate ����
	//MemoryBlockHandle->Deallocate(mem);
	if (mem)
	{
		auto p = m_MemoryChunk;

		m_MemoryChunk = reinterpret_cast<CBlockUnit*>(mem);
		m_MemoryChunk->setNext(p);
	}
}
