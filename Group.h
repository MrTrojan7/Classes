#pragma once
#include "AllLibraries.h"
#include "Student.h"
class Group
{
private:
	Student* _student = nullptr;
	unsigned int _quantity;
	char* _name = nullptr;
	char* _specialization = nullptr;
	unsigned int _course;
	void SetQuantity(unsigned int quantity);
public:
	Group();
	Group(unsigned int quantity);
	Group(const char* name, const char* specialization,
		const unsigned int course, const unsigned int quantity);
	Group(const Group& group);
	void SetNameOfGroup(const char* name);
	void SetSpecializationOfGroup(const char* specialization);
	void SetCourse(unsigned int course);

	const void ShowAllStudents() const;
	void AddStudents(Student& student);
	void EditingGroup(const char* name, const char* specialization,
		const unsigned int course);
	void Merge(Group& group);
	static void Transfer(Group& group1, Group& group2);
	void ExpulsionStudent(unsigned int num);
	void CheckNumOfStudent(unsigned int& num);
	void OnceExpulsion();
	void ALotOfExpulsion();
	void CalculationOfExpulsionStudent(unsigned int criterion);
	void SortGroup();
	const unsigned int GetQuantity() const;
	const char* const GetName() const;
	const unsigned int const GetCourse() const;
	const char* const GetSpecialization() const;
	Group operator+=(Student& student);
	bool operator > (Group& group);
	bool operator < (Group& group);
	bool operator == (Group& group);
	bool operator != (Group& group);
	void operator = (Group& group);
	Group operator()(const char* name, const char* specialization,
		const unsigned int course, const unsigned int quantity);
	Student operator[] (unsigned int index);
	friend ostream& operator << (ostream& out, const Group& original);
	friend istream& operator >> (istream& in, Group& original);
	~Group();
};