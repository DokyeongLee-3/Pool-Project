#define _CRT_SECURE_NO_WARNINGS

#include "CObject.h"
#include <iostream>

CObject::CObject() : HP(1000), MaxHP(1000), MP(300), MaxMP(300), Attack(100), Armor(50)
{
	 //std::cout << "constructor" << std::endl;
}

CObject::~CObject()
{
}

CObject::CObject(const CObject& obj)
{
	std::cout << "copy constructor" << std::endl;
	HP = obj.HP;
	MP = obj.MP;
	MaxHP = obj.MaxHP;
	MaxMP = obj.MaxMP;
	Attack = obj.Attack;
	Armor = obj.Armor;
	strncpy(name, obj.name, 32);
}

CObject& CObject::operator=(const CObject& obj)
{
	std::cout << "assignment operator" << std::endl;
	HP = obj.HP;
	MP = obj.MP;
	MaxHP = obj.MaxHP;
	MaxMP = obj.MaxMP;
	Attack = obj.Attack;
	Armor = obj.Armor;
	strcpy(name, obj.name);

	return *this;
}
/*
CObject::CObject(CObject&& obj)
{
}
*/

