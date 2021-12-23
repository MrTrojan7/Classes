#include "Group.h"

Group::Group() : Group("SPU121", "Programming", 1, 4){}

Group::Group(unsigned int quantity): Group("SPU121", "Programming", 1, quantity){}

Group::Group(const char* name, const char* specialization, 
	const unsigned int course, const unsigned int quantity)
{
	if (this->_student != nullptr)
	{
		delete[]this->_student;
	}
	SetNameOfGroup(name);
	SetSpecializationOfGroup(specialization);
	SetQuantity(quantity);
	SetCourse(course);
	this->_student = new Student[GetQuantity()]; //lost time...
}

Group::Group (const Group& group) : Group(group._name, group._specialization, group._course, group._quantity){}

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

const void Group::ShowAllStudents() const
{
	cout << "\nName of group: " << GetName() << endl;
	cout << "Specialization: " << GetSpecialization() << endl;
	cout << "Course: " << GetCourse() << endl;
	cout << "Quantity: " << GetQuantity() << endl;
	for (int i = 0; i < GetQuantity(); i++)
	{
		this->_student[i].Show();
		cout << endl;
	}
}

const unsigned int Group::GetQuantity() const
{
	return this->_quantity;
}

const char* const Group::GetName() const
{
	return this->_name;
}

unsigned int const Group::GetCourse() const
{
	return this->_course;
}

const char* const Group::GetSpecialization() const
{
	return this->_specialization;
}

Group::~Group()
{
	cout << "Group Dest!\n";
	if (_student != nullptr)
		delete[]_student;
	if (_specialization != nullptr)
		delete[]_specialization;
	if (_name != nullptr)
		delete[]_name;
}
