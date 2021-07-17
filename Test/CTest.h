#pragma once
#include <iostream>
#include <memory>
#include <chrono>
#include "..\MemoryPool\MemoryPoolManager\CMemoryPoolManager.h"
#include "..\ObjectPool\ObjectPoolManager\CObjectPoolManager.h"

//#define arena_size 1000
#define TEST_LOOP_COUNT 1000000
//#define TEST_LOOP_COUNT 1
//#define MEMORY_POOL 1
#define OBJECT_POOL 2

using namespace std::chrono;

class CTest
{
public:
	CTest();
	~CTest();

private:
	std::unique_ptr<CMemoryPoolManager> MemoryPoolManager;
	std::unique_ptr<CObjectPoolManager> ObjectPoolManager;

public:
	// Test start -> �޸� Ǯ ���/�̻�� ��� ����
	void Run();

	// �޸� Ǯ ���� 
	void RunPool();
	void NotUsePool();

};

