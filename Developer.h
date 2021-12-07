#pragma once
class Developer
{
private:
	bool _isAlive;
	bool _isDrunk;
	bool _isHungry;
	bool _isWork;
	char* _name;
	char* _company;

public:
	Developer();
	Developer(bool IsAlive, bool IsDrunk, bool IsHungry, 
		bool IsWork, const char* name, const char* company);
	int GetIsAlive() const;
	int GetIsDrunk() const;
	int GetIsHungry() const;
	int GetIsWork() const;
	char* GetCompany() const;
	char* GetName() const;

	void SetIsAlive(bool IsAlive);
	void SetIsDrunk(bool IsDrunk);
	void SetIsHungry(bool IsHungry);
	void SetIsWork(bool IsWork);
	void SetCompany(const char* company);
	void SetName(const char* name);

	void Print();
	~Developer();
};

