#include "CObjectPoolManager.h"
#include <iostream>

CObjectPoolManager::CObjectPoolManager(int count) : m_InitObjectCount(count)
{
	// 생성자 호출될 때 인자만큼 stack에 미리 오브젝트 공간 reserve
	m_ObjectVector.reserve(m_InitObjectCount);
	for (int i = 0; i < m_InitObjectCount; ++i)
	{
		m_ObjectVector.emplace_back(new CObject);
	}
}

CObjectPoolManager::~CObjectPoolManager()
{
	while (!m_ObjectVector.empty())
	{
		CObject* tmp = m_ObjectVector.back();
		m_ObjectVector.pop_back();
		delete tmp;
	}
}

CObject* CObjectPoolManager::Allocate()
{

	// 스택에 있는 모든 object들이 사용중일 때 다시 30개씩 채워넣기
	if (m_ObjectVector.empty())
	{
		for (int i = 0; i < 30; ++i)
		{
			// 객체를 값으로 전달하는 것이 아닌 포인터를 push하는 것이므로
			// 복사 생성자나 만약 move 생성자가 정의 되어 있다면 move 생성자를
			// 호출하지 않는다. 따라서 push_back과 emplace_back의 성능차이는 크지 않을 것으로 예상
			m_ObjectVector.emplace_back(new CObject());
			//m_ObjectVector.push_back(new CObject());
		}
	}
	
	CObject* ret = m_ObjectVector.back();
	m_ObjectVector.pop_back();

	return ret;
}

void CObjectPoolManager::Deallocate(CObject* obj)
{
	// 객체를 값으로 전달하는 것이 아닌 포인터를 push하는 것이므로
	// 복사 생성자나 만약 move 생성자가 정의 되어 있다면 move 생성자를
	// 호출하지 않는다. 따라서 push_back과 emplace_back의 성능차이는 크지 않을 것으로 예상
	m_ObjectVector.emplace_back(obj);
	//m_ObjectVector.push_back(obj);
}
