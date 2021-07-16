#pragma once
#include <iostream>
#include <memory>
#include <chrono>
#include "..\MemoryPool\MemoryPoolManager\CMemoryPoolManager.h"

#define arena_size 1000
#define TEST_LOOP_COUNT 100000000
//#define TEST_LOOP_COUNT 1
#define MEMORY_POOL

using namespace std::chrono;

class CTest
{
public:
	CTest();
	~CTest();

private:
	std::unique_ptr<CMemoryPoolManager> PoolManager;

public:
	// Test start -> 메모리 풀 사용/미사용 모두 실행
	void Run();

	// 메모리 풀 만들어서 
	void RunPool();
	void NotUsePool();

};

