#include <iostream>
#include "..\Test\CTest.h"

//어떤 pool을 테스트 해볼지 매크로로 결정
 #define MemoryPool
// #define ObjectPool

using namespace std;

int main()
{
	// 여기서 MemoryPool인지, ObjectPool인지 나눌 필요 없이 CTest::RunPool()에서 나누면 됨
	CTest PoolTest;
	PoolTest.Run();

	return 0;
}
