#include <iostream>
#include "..\Test\CTest.h"

//� pool�� �׽�Ʈ �غ��� ��ũ�η� ����
 #define MemoryPool
// #define ObjectPool

using namespace std;

int main()
{
	// ���⼭ MemoryPool����, ObjectPool���� ���� �ʿ� ���� CTest::RunPool()���� ������ ��
	CTest PoolTest;
	PoolTest.Run();

	return 0;
}
