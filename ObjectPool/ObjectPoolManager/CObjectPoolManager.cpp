#include "CObjectPoolManager.h"
#include <iostream>

CObjectPoolManager::CObjectPoolManager(int count) : m_InitObjectCount(count)
{
	// ������ ȣ��� �� ���ڸ�ŭ stack�� �̸� ������Ʈ ���� reserve
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

	// ���ÿ� �ִ� ��� object���� ������� �� �ٽ� 30���� ä���ֱ�
	if (m_ObjectVector.empty())
	{
		for (int i = 0; i < 30; ++i)
		{
			// ��ü�� ������ �����ϴ� ���� �ƴ� �����͸� push�ϴ� ���̹Ƿ�
			// ���� �����ڳ� ���� move �����ڰ� ���� �Ǿ� �ִٸ� move �����ڸ�
			// ȣ������ �ʴ´�. ���� push_back�� emplace_back�� �������̴� ũ�� ���� ������ ����
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
	// ��ü�� ������ �����ϴ� ���� �ƴ� �����͸� push�ϴ� ���̹Ƿ�
	// ���� �����ڳ� ���� move �����ڰ� ���� �Ǿ� �ִٸ� move �����ڸ�
	// ȣ������ �ʴ´�. ���� push_back�� emplace_back�� �������̴� ũ�� ���� ������ ����
	m_ObjectVector.emplace_back(obj);
	//m_ObjectVector.push_back(obj);
}
