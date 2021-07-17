#pragma once
class CObject
{
private:
	char name[32];
	int HP;
	int MaxHP;
	int MP;
	int MaxMP;
	int Attack;
	int Armor;
	
public:
	CObject();
	~CObject();
	
	// ���� ������
	CObject(const CObject& obj);
	// ���� ������
	CObject& operator=(const CObject& obj);
	// move ������
	//CObject(CObject&& obj);

};

