#include "CTest.h"

CTest::CTest()
{
#ifdef MEMORY_POOL
	MemoryPoolManager = std::make_unique<CMemoryPoolManager>(arena_size);
#elif OBJECT_POOL
#endif
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
	ObjectPoolManager = std::make_unique<CObjectPoolManager>(30);
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
		int* ptr1 = reinterpret_cast<int*>(MemoryPoolManager->Allocate(100));

		MemoryPoolManager->Deallocate(ptr1);
	}
#elif OBJECT_POOL
	for (int i = 0; i < TEST_LOOP_COUNT; ++i)
	{
		CObject* obj1 = ObjectPoolManager->Allocate();
		CObject* obj2 = ObjectPoolManager->Allocate();
		CObject* obj3 = ObjectPoolManager->Allocate();
		CObject* obj4 = ObjectPoolManager->Allocate();
		CObject* obj5 = ObjectPoolManager->Allocate();
		CObject* obj6 = ObjectPoolManager->Allocate();
		CObject* obj7 = ObjectPoolManager->Allocate();
		CObject* obj8 = ObjectPoolManager->Allocate();
		CObject* obj9 = ObjectPoolManager->Allocate();
		CObject* obj10 = ObjectPoolManager->Allocate();
		CObject* obj11 = ObjectPoolManager->Allocate();
		CObject* obj12 = ObjectPoolManager->Allocate();
		CObject* obj13 = ObjectPoolManager->Allocate();
		CObject* obj14 = ObjectPoolManager->Allocate();
		CObject* obj15 = ObjectPoolManager->Allocate();
		CObject* obj16 = ObjectPoolManager->Allocate();
		CObject* obj17 = ObjectPoolManager->Allocate();
		CObject* obj18 = ObjectPoolManager->Allocate();
		CObject* obj19 = ObjectPoolManager->Allocate();
		CObject* obj20 = ObjectPoolManager->Allocate();

		ObjectPoolManager->Deallocate(obj1);
		ObjectPoolManager->Deallocate(obj2);
		ObjectPoolManager->Deallocate(obj3);
		ObjectPoolManager->Deallocate(obj4);
		ObjectPoolManager->Deallocate(obj5);
		ObjectPoolManager->Deallocate(obj6);
		ObjectPoolManager->Deallocate(obj7);
		ObjectPoolManager->Deallocate(obj8);
		ObjectPoolManager->Deallocate(obj9);
		ObjectPoolManager->Deallocate(obj10);
		ObjectPoolManager->Deallocate(obj11);
		ObjectPoolManager->Deallocate(obj12);
		ObjectPoolManager->Deallocate(obj13);
		ObjectPoolManager->Deallocate(obj14);
		ObjectPoolManager->Deallocate(obj15);
		ObjectPoolManager->Deallocate(obj16);
		ObjectPoolManager->Deallocate(obj17);
		ObjectPoolManager->Deallocate(obj18);
		ObjectPoolManager->Deallocate(obj19);
		ObjectPoolManager->Deallocate(obj20);
	}

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
	for (int i = 0; i < TEST_LOOP_COUNT; ++i)
	{
		CObject* obj1 = new CObject();
		CObject* obj2 = new CObject();
		CObject* obj3 = new CObject();
		CObject* obj4 = new CObject();
		CObject* obj5 = new CObject();
		CObject* obj6 = new CObject();
		CObject* obj7 = new CObject();
		CObject* obj8 = new CObject();
		CObject* obj9 = new CObject();
		CObject* obj10 = new CObject();
		CObject* obj11 = new CObject();
		CObject* obj12 = new CObject();
		CObject* obj13 = new CObject();
		CObject* obj14 = new CObject();
		CObject* obj15 = new CObject();
		CObject* obj16 = new CObject();
		CObject* obj17 = new CObject();
		CObject* obj18 = new CObject();
		CObject* obj19 = new CObject();
		CObject* obj20 = new CObject();

		delete obj1;
		delete obj2;
		delete obj3;
		delete obj4;
		delete obj5;
		delete obj6;
		delete obj7;
		delete obj8;
		delete obj9;
		delete obj10;
		delete obj11;
		delete obj12;
		delete obj13;
		delete obj14;
		delete obj15;
		delete obj16;
		delete obj17;
		delete obj18;
		delete obj19;
		delete obj20;

	}
#endif
}
