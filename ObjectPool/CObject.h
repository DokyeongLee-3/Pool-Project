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
	
	// 복사 생성자
	CObject(const CObject& obj);
	// 대입 연산자
	CObject& operator=(const CObject& obj);
	// move 연산자
	//CObject(CObject&& obj);

};

