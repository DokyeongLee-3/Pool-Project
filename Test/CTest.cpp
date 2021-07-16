#include "CTest.h"

CTest::CTest()
{
	PoolManager = std::make_unique<CMemoryPoolManager>(arena_size);
}

CTest::~CTest()
{
}

void CTest::Run()
{
#ifdef MEMORY_POOL
	std::cout << "Using memory pool..." << std::endl;
#elif OBJECT_POOL
	std::cout << "Using Object Pool..." << std::endl;
#endif

	auto start = std::chrono::high_resolution_clock::now();
	RunPool();
	auto end = std::chrono::high_resolution_clock::now();
	duration<double> ElapsedTime = end - start;

#ifdef MEMORY_POOL
	std::cout << "Elapsed Time Using MemoryPool: " << ElapsedTime.count() << std::endl;
#elif OBJECT_POOL
	std::cout << "Elapsed Time Using ObjectPool: " << ElapsedTime.count() << std::endl;
#endif

#ifdef MEMORY_POOL
	std::cout << "Not using memory pool..." << std::endl;
#elif OBJECT_POOL
	std::cout << "Not using Object Pool..." << std::endl;
#endif

	start = std::chrono::high_resolution_clock::now();
	NotUsePool();
	end = std::chrono::high_resolution_clock::now();

	ElapsedTime = end - start;
#ifdef MEMORY_POOL
	std::cout << "Elapsed Time Not Using MemoryPool: " << ElapsedTime.count() << std::endl;
#elif OBJECT_POOL
	std::cout<< "Elapsed Time Not Using ObjectPool: " << ElapsedTime.count() << std::endl;
#endif

}

void CTest::RunPool()
{
#ifdef MEMORY_POOL

		for (int i = 0; i < TEST_LOOP_COUNT; ++i)
		{
			int* ptr1 = reinterpret_cast<int*>(PoolManager->Allocate(100));

			PoolManager->Deallocate(ptr1);

		}
#elif OBJECT_POOL

#endif
}

void CTest::NotUsePool()
{
#ifdef MEMORY_POOL
	for (int i = 0; i < TEST_LOOP_COUNT; ++i)
	{
		int* ptr1 = (int*)malloc(100);

		free(ptr1);
	}
#elif OBJECT_POOL

#endif
}
