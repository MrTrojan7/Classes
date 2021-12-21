#pragma once
#include "AllLibraries.h"
#include "Student.h"
class Group
{
private:
	Student* _student;
	unsigned int _quantity;
	char* _name;
	char* _specialization;
	unsigned int _course;
public:
	Group();
	Group(unsigned int quantity);
	Group(const char* name, const char* specialization,
		unsigned int course, unsigned int quantity);
	Group(const Group &group);
	void SetNameOfGroup(const char* name);
	void SetSpecializationOfGroup(const char* specialization);
	void SetQuantity(unsigned int quantity);
	void SetCourse(unsigned int course);
	void ShowAllStudents() const;
	void AddStudent(Student& student, int index);
	static void EditingGroup(Group& group);
	static void Compozition(Group& group1, Group& group2);
	static void Transfer(Group& group1, Group& group2);
	void OnceExpulsion();
	void ALotOfExpulsion();
	void SortSurname();
	~Group();
};

