#include "Student.h"

void Student::SetSurame(const char* surname)
{
    this->surname = new char[strlen(surname) + 1];
    strcpy_s(this->surname, strlen(surname) + 1, surname);
}

void Student::SetName(const char* name)
{
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
}


void Student::SetPatronymic(const char* patronymic)
{
    this->patronymic = new char[strlen(patronymic) + 1];
    strcpy_s(this->patronymic, strlen(patronymic) + 1, patronymic);
}


void Student::SetBirthday(Date _birthday)
{
    GetCheckZero(_birthday.day, _birthday.month, _birthday.year);
    this->birthday.day = _birthday.day;
    this->birthday.month = _birthday.month;
    this->birthday.year = _birthday.year;
}

void Student::SetAdress(const char* adress)
{
    this->adress = new char[strlen(adress) + 1];
    strcpy_s(this->adress, strlen(adress) + 1, adress);
}

void Student::SetPhone(PHONE _phone)
{
    GetCheckZero(_phone.mob, _phone.home, _phone.work);
    this->phone.mob = _phone.mob;
    this->phone.home = _phone.home;
    this->phone.work = _phone.work;
}

char* Student::GetSurname() const
{
    return surname;
}

char* Student::GetName() const
{
    return name;
}

void Student::SetEvaluations(Rating _evaluation)
{
    GetCheckZero(_evaluation.ev1, _evaluation.ev2, _evaluation.ev3);
    this->mas1.push_back(_evaluation.ev1);
    this->mas2.push_back(_evaluation.ev2);
    this->mas3.push_back(_evaluation.ev3);
}

char* Student::GetPatronymic() const
{
    return patronymic;
}

void Student::GetBirthday(const Date date) const
{
    cout << date.day << "/" << date.month << "/" << date.year << "\n";
}

char* Student::GetAdress() const
{
    return  adress;
}

void Student::GetEvaluations(const vector <int> mas) const
{
    for (size_t i = 0; i < mas.size(); i++)
    {
        cout << mas[i] << " ";
    }
}

bool Student::GetCheckZero(int val1, int val2, int val3) const
{
    if (!val1 || !val2 || !val3)
    {
        throw "Invalid value! It should not be equal to zero!";
    }
    return true;
}

int Student::GetPhone(int phone) const
{
    return phone;
}

void Student::Show()
{
    cout << "Surname: " << GetSurname() << "\n";
    cout << "Name: " << GetName() << "\n";
    cout << "Patronymic: " << GetPatronymic() << "\n";
    cout << "Birthday date: "; 
    GetBirthday(this->birthday);
    cout << "Home Adress: " << "str. " << GetAdress() << "\n";
    cout << "Telephone number:\n"
        << "Mobile number: " << GetPhone(this->phone.mob) << "\n"
        << "Home number: " << GetPhone(this->phone.home) << "\n"
        << "Job number: " << GetPhone(this->phone.work) << "\n";
    cout << "Grades of subject 1: ";
    GetEvaluations(mas1);
    cout << "\nGrades of subject 2: ";
    GetEvaluations(mas2);
    cout << "\nGrades of subject 3: ";
    GetEvaluations(mas3);
    cout << endl;

}

Student::Student(const char* Surname, const char* Name, 
    const char* Patronymic, Date _Birthday,
    const char* Adress, PHONE _Phone, Rating _Evaluation)
{
    SetSurame(Surname);
    SetName(Name); 
    SetPatronymic(Patronymic);
    SetBirthday(_Birthday);
    SetAdress(Adress);
    SetPhone(_Phone);
    SetEvaluations(_Evaluation);
}

Student::Student() : Student("Fedko", "Vasya", "Vasilievich",
    { 1, 1, 2000 }, "Chernyahovskogo 2", { 123456789 ,12345, 123 }, { 12, 11, 10 })
{
}

Student::~Student()
{
    //cout << "DEST\n";
    delete[]this->name;
    delete[]this->surname;
    delete[]this->patronymic;
    delete[]this->adress;
}