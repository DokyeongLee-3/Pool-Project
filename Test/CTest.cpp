#include "CTest.h"

CTest::CTest()
{
	PoolManager = std::make_unique<CPoolManager>(arena_size);
}

CTest::~CTest()
{
}

void CTest::Run()
{
#ifdef MEMORY_POOL
	std::cout << "Using memory pool..." << std::endl;
	auto start = std::chrono::high_resolution_clock::now();
	RunPool();
	auto end = std::chrono::high_resolution_clock::now();

	duration<double> ElapsedTime = end - start;

	std::cout << "Elapsed Time Using MemoryPool: " << ElapsedTime.count() << std::endl;


	std::cout << "Not using memory pool..." << std::endl;
	start = std::chrono::high_resolution_clock::now();
	NotUsePool();
	end = std::chrono::high_resolution_clock::now();

	ElapsedTime = end - start;

	std::cout << "Elapsed Time Not Using MemoryPool: " << ElapsedTime.count() << std::endl;

#elif

#endif
}

void CTest::RunPool()
{
		for (int i = 0; i < TEST_LOOP_COUNT; ++i)
		{
			int* ptr1 = reinterpret_cast<int*>(PoolManager->Allocate(100));


			PoolManager->Deallocate(ptr1);

		}
}

void CTest::NotUsePool()
{
	for (int i = 0; i < TEST_LOOP_COUNT; ++i)
	{
		int* ptr1 = (int*)malloc(100);


		free(ptr1);
	}
}
