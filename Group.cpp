#include "Group.h"

Group::Group() : Group("SPU121", "Programming", 1, 4)
{
}

Group::Group(unsigned int quantity): Group("SPU121", "Programming", 1, quantity)
{
}

Group::Group(const char* name, const char* specialization, unsigned int course, unsigned int quantity)
{
	SetNameOfGroup(name);
	SetSpecializationOfGroup(specialization);
	SetQuantity(quantity);
	SetCourse(course);
	this->_student = new Student[quantity];
	for (int i = 0; i < quantity; i++)
	{
		Student test;
		AddStudent(test, i);
	}
}

void Group::SetNameOfGroup(const char* name)
{
	this->_name = new char[strlen(name) + 1];
	strcpy_s(this->_name, strlen(name) + 1, name);
}

void Group::SetSpecializationOfGroup(const char* specialization)
{
	this->_specialization = new char[strlen(specialization) + 1];
	strcpy_s(this->_specialization, strlen(specialization) + 1, specialization);
}

void Group::SetQuantity(unsigned int quantity)
{
	this->_quantity = quantity;
}

void Group::SetCourse(unsigned int course)
{
	this->_course = course;
}

void Group::ShowAllStudents() const
{
	for (int i = 0; i < this->_quantity; i++)
	{
		this->_student[i].Show();
	}
}

void Group::AddStudent(Student& student, int index)
{
	this->_student[index] = student;
}

Group::~Group()
{
	if(this->_student != nullptr)
		delete[] this->_student;
	if (this->_specialization != nullptr)
		delete[] this->_specialization;
	if (this->_name != nullptr)
		delete[] this->_name;
}
