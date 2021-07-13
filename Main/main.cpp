#include <iostream>
#include "..\Test\CTest.h"

#define MemoryPool
// #define ObjectPool

using namespace std;

int main()
{
#ifdef MemoryPool
	CTest MemoryPoolTest;
	MemoryPoolTest.Run();
#elif

#endif
}