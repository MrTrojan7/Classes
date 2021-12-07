#include "Developer.h"
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

Developer::Developer() : Developer (1, 0, 0, 1, "Ivan", "Google")
{
}

Developer::Developer(bool IsAlive, bool IsDrunk, bool IsHungry, 
	bool IsWork, const char* name, const char* company)
{
	SetIsAlive(IsAlive);
	SetIsDrunk(IsDrunk);
	SetIsHungry(IsHungry);
	SetIsWork(IsWork);
	this->_name = new char[100];
	SetName(name);
	this->_company = new char[100];
	SetCompany(company);
}

int Developer::GetIsAlive() const
{
	return _isAlive;
}

int Developer::GetIsDrunk() const
{
	return _isDrunk;
}

int Developer::GetIsHungry() const
{
	return _isHungry;
}

int Developer::GetIsWork() const
{
	return _isWork;
}

char* Developer::GetCompany() const
{
	return _company;
}

char* Developer::GetName() const
{
	return _name;
}

void Developer::SetIsAlive(bool IsAlive)
{
	_isAlive = IsAlive;
}

void Developer::SetIsDrunk(bool IsDrunk)
{
	_isDrunk = IsDrunk;
}

void Developer::SetIsHungry(bool IsHungry)
{
	_isHungry = IsHungry;
}

void Developer::SetIsWork(bool IsWork)
{
	_isWork = IsWork;
}

void Developer::SetCompany(const char* company)
{
	strcpy_s(_company, 99, company);
}

void Developer::SetName(const char* name)
{
	strcpy_s(_name, 99, name);
}

void Developer::Print()
{
	cout << GetName() << ", ";
	if (_isWork)
	{
		cout << "you are at work.\n";
		if (!_isAlive || _isHungry || _isDrunk)
		{
			cout << "\"Something is wrong?\"\n";
		}
		else
		{
			cout << "Everything is fine\n";
		}
	}
	else
	{
		(_isAlive && !_isHungry && !_isDrunk) ? cout << "Go work on galley!\n" : cout << "What\'s happened?\n";
	}
}

Developer::~Developer()
{
	delete[] _name;
	delete[] _company;
}
