#pragma once
#include <iostream>
#include <memory>
#include <chrono>
#include "..\MemoryPool\PoolManager\CPoolManager.h"

#define arena_size 1000
#define TEST_LOOP_COUNT 10000000
//#define TEST_LOOP_COUNT 1
#define MEMORY_POOL

using namespace std::chrono;

class CTest
{
public:
	CTest();
	~CTest();

private:
	std::unique_ptr<CPoolManager> PoolManager;

public:
	// Test start -> �޸� Ǯ ���/�̻�� ��� ����
	void Run();

	// �޸� Ǯ ���� 
	void RunPool();
	void NotUsePool();

};

