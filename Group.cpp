#include "Group.h"

Group::Group() : Group("SPU121", "Programming", 1, 0){}

Group::Group(unsigned int quantity): Group("SPU121", "Programming", 1, quantity){}

Group::Group(const char* name, const char* specialization, 
	const unsigned int course, const unsigned int quantity)
{
	SetNameOfGroup(name);
	SetSpecializationOfGroup(specialization);
	SetQuantity(quantity);
	SetCourse(course);
	if (GetQuantity() > 0)
	{
		this->_student = new Student[GetQuantity()];
	}
}

Group::Group (const Group& group) : Group(group._name, group._specialization, group._course, group._quantity){}

void Group::SetNameOfGroup(const char* name)
{
	if (!name || strlen(name) == 0)
		return;
	if (this->_name != nullptr)
	{
		delete[] this->_name;
	}
	this->_name = new char[strlen(name) + 1];
	strcpy_s(this->_name, strlen(name) + 1, name);
	name = _name;
}

void Group::SetSpecializationOfGroup(const char* specialization)
{
	if (!specialization || strlen(specialization) == 0)
		return;
	if (this->_specialization != nullptr)
	{
		delete[] this->_specialization;
	}
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
	if (GetQuantity() > 0)
	{
		for (int i = 0; i < GetQuantity(); i++)
		{
			cout << this->_student[i].GetSurname() << "\n";
			cout << this->_student[i].GetName() << "\n";
		}
	}
}

void Group::EditingGroup(const char* name, const char* specialization,
	const unsigned int course)
{
	SetNameOfGroup(name);
	SetSpecializationOfGroup(specialization);
	SetCourse(course);
}

void Group::Transfer(Group& group1, Group& group2)
{
}

void Group::Merge(Group& group) // в параметры передается группа, которую мержим и удаляем
{
	Student* tmp = new Student[group._quantity + GetQuantity()];
	for (int i = 0; i < this->GetQuantity(); i++)
	{
		tmp[i] = this->_student[i];
	}
	for (int i = 0; i < group.GetQuantity(); i++)
	{
		tmp[i + this->GetQuantity()] = group._student[i];
	}
	SetQuantity(group._quantity + GetQuantity());
	group.~Group();
	if (this->_student != nullptr)
		delete[] this->_student;
	this->_student = tmp;
}

void Group::AddStudents(Student& student) 
{
	Student* tmp = new Student[GetQuantity() + 1];
	if (!GetQuantity())
	{
		this->_student = new Student[GetQuantity() + 1];
	}
	if (GetQuantity())
	{
		for (int i = 0; i < GetQuantity(); i++)
		{
			tmp[i] = this->_student[i];
		}
	}
	tmp[GetQuantity()] = student;
	SetQuantity(GetQuantity() + 1);
	
	if (this->_student != nullptr)
		delete[] this->_student;
	this->_student = tmp;
}

void Group::SortGroup()
{
	for (int i = 0; i < GetQuantity(); i++)
	{
		bool flag = true;
		for (int j = 0; j < GetQuantity(); j++)
		{
			if ((j + 1) < GetQuantity())
			{
				if (_student[j] > _student[j + 1])
				{
					flag = false;
					swap(_student[j], _student[j + 1]); //убрать
				}
			}
		}
		if (flag)
		{
			break;
		}
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
	if (_student != nullptr)
		delete[]_student;
	if (_specialization != nullptr)
		delete[]_specialization;
	if (_name != nullptr)
		delete[]_name;
}
