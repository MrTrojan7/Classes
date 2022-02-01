#include "Group.h"

Group::Group() : Group("SPU121", "Programming", 1, 0) {} 

Group::Group(unsigned int quantity) : Group("SPU121", "Programming", 1, quantity) {} 

Group::Group(const char* name, const char* specialization,
	const unsigned int course, const unsigned int quantity) 
{
	SetNameOfGroup(name);
	SetSpecializationOfGroup(specialization);
	SetQuantity(quantity);
	SetCourse(course);
	if (GetQuantity() > 0)
		this->_student = new Student[GetQuantity()];
}

Group::Group(const Group& group)
{
	SetNameOfGroup(group._name);
	SetSpecializationOfGroup(group._specialization);
	SetQuantity(group._quantity);
	SetCourse(group._course);
	if (GetQuantity() > 0)
	{
		this->_student = new Student[GetQuantity()];
		for (int i = 0; i < GetQuantity(); i++)
			this->_student[i] = group._student[i];
	}
}


void Group::SetNameOfGroup(const char* name)
{
	if (!name || strlen(name) == 0)
		return;
	if (this->_name != nullptr)
		delete[] this->_name;
	this->_name = new char[strlen(name) + 1];
	strcpy_s(this->_name, strlen(name) + 1, name);
	name = _name;
}

void Group::SetSpecializationOfGroup(const char* specialization)
{
	if (!specialization || strlen(specialization) == 0)
		return;
	if (this->_specialization != nullptr)
		delete[] this->_specialization;
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
			cout << (i + 1) << ") " << this->_student[i].GetSurname() << "\n";
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
	if (GetQuantity())
	{
		unsigned int num = 0;
		cout << "Editing\n";
		cin >> num;
		_student[--num].EditingStudent();
	}
}

void Group::Transfer(Group& group1, Group& group2)
{
	if (group1.GetQuantity())
	{
		unsigned int num = 0;
		cout << "Transfer\n";
		group1.CheckNumOfStudent(num);
		group2.AddStudents(group1._student[num]);
		group1.ExpulsionStudent(num);
	}
}

void Group::Merge(Group& group)
{
	Student* tmp = new Student[group._quantity + GetQuantity()];
	for (int i = 0; i < this->GetQuantity(); i++)
		tmp[i] = this->_student[i];
	for (int i = 0; i < group.GetQuantity(); i++)
		tmp[i + this->GetQuantity()] = group._student[i];
	SetQuantity(group._quantity + GetQuantity());
	group.~Group();
	if (this->_student != nullptr)
		delete[] this->_student;
	this->_student = tmp;
}

void Group::OnceExpulsion() // ���������� ������
{
	int min = _student[0].CheckGrades();
	int index = 0;
	for (int i = 0; i < GetQuantity(); i++)
	{
		if (_student[i].CheckGrades() < min)
		{
			index = i;
			min = _student[i].CheckGrades();
		}
	}
	cout << "Student " << _student[index].GetSurname() << " is expelled from university!\n";
	ExpulsionStudent(index);
}

void Group::CalculationOfExpulsionStudent(unsigned int criterion)
{
	for (int i = 0; i < GetQuantity(); i++)
	{
		if (_student[i].CheckGrades() <= criterion)
			ExpulsionStudent(i);
	}
}

void Group::ALotOfExpulsion()
{
	unsigned int criterion = 6;
	do
	{
		cout << "Enter criterion of grade\n"
			"(if grade <= criterion, student will be expelled!\n"
			"default = 6)\n";
		cin >> criterion;
	} while (criterion <= 0 || criterion > 12);
	CalculationOfExpulsionStudent(criterion);
}

void Group::ExpulsionStudent(unsigned int num)
{
	Student* tmp = new Student[GetQuantity() - 1];
	SetQuantity(GetQuantity() - 1);
	bool flag = false;
	for (int i = 0; i < GetQuantity(); i++)
	{
		if (i == num)
			flag = true;
		tmp[i] = _student[i + flag];
	}
	if (_student != nullptr)
	{
		delete[] _student;
		_student = nullptr;
	}
	_student = tmp;
}

void Group::CheckNumOfStudent(unsigned int& num)
{
	do
	{
		cout << "Enter number of student:\n";
		cin >> num;
	} while (num <= 0 || num > GetQuantity());
	--num;
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
				if (_student[j] > _student[(j + 1)])
				{
					flag = false;
					Student tmp;
					tmp = _student[j];
					_student[j] = _student[(j + 1)];
					_student[j + 1] = tmp;
				}
			}
		}
		if (flag)
			break;
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
	{
		delete[]_student;
		_student = nullptr;
	}

	if (_specialization != nullptr)
	{
		delete[]_specialization;
		_specialization = nullptr;
	}
	if (_name != nullptr)
	{
		delete[]_name;
		_name = nullptr;
	}
}