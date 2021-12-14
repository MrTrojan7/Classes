#include "Student.h"

void Student::SetSurame(char* surname)
{
    if (!surname || strlen(surname) == 0)
        return;

    if (this->surname != nullptr)
    {
        delete[]this->surname;
    }

    this->surname = new char[strlen(surname) + 1];
    strcpy_s(this->surname, strlen(surname) + 1, surname);
}

void Student::SetName(char* name)
{
    if (!name || strlen(name) == 0)
        return;

    if (this->name != nullptr)
    {
        delete[]this->name;
    }

    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name, strlen(name) + 1, name);
}


void Student::SetPatronymic(char* patronymic)
{
    if (!patronymic || strlen(patronymic) == 0)
        return;

    if (this->patronymic != nullptr)
    {
        delete[]this->patronymic;
    }

    this->patronymic = new char[strlen(patronymic) + 1];
    strcpy_s(this->patronymic, strlen(patronymic) + 1, patronymic);
}


Date Student::SetBirthday(Date _birthday)
{
    this->birthday.day = _birthday.day;
    this->birthday.month = _birthday.month;
    this->birthday.year = _birthday.year;
}

void Student::SetAdress(char* adress)
{
    if (!adress || strlen(adress) == 0)
        return;

    if (this->adress != nullptr)
    {
        delete[]this->adress;
    }

    this->adress = new char[strlen(adress) + 1];
    strcpy_s(this->adress, strlen(adress) + 1, adress);
}

PHONE Student::SetPhone(PHONE _phone)
{
        this->phone.mob = _phone.mob;
        this->phone.home = _phone.home;
        this->phone.work = _phone.work;
}

const char* const Student::GetSurname() const
{
    return surname;
}

const char* const Student::GetName() const
{
    return name;
}

Rating Student::SetEvaluations(Rating _evaluation)
{
    this->evaluation.mas1.push_back(_evaluation.ev1);
    this->evaluation.mas2.push_back(_evaluation.ev2);
    this->evaluation.mas3.push_back(_evaluation.ev3);
}

const char* const Student::GetPatronymic() const
{
    return patronymic;
}

Date Student::GetBirthday() const
{
    return birthday;
}

const char* const Student::GetAdress() const
{
    return  adress;
}

PHONE Student::GetPhone() const
{
    return phone;
}

void Student::Show()
{
    cout << "фамилия: " << surname << "\n";
    cout << "имья: " << name << "\n";
    cout << "отчество: " << patronymic << "\n";
    cout << "дата рождения: " << birthday.day << "." << birthday.month << "." << birthday.year << "\n";
    cout << "домашный адресс: " << "ул. " << adress << "\n";
    cout << "телефонный номер:\n"
        << "моб. номер: " << phone.mob << "\n"
        << "дом. номер: " << phone.home << "\n"
        << "роб. номер: " << phone.work << "\n";
    cout << "\n";
}

Student::Student()/* : Student("Fedko", "Vasya", "Vasilievich",
    { 11, 12, 2000 }, "Chernyahovskogo 1", { 1212, 2222, 1111 })*/
{
}

Student::Student(const char* Surname, char* Name, 
    char* Patronymic, Date _Birthday, 
    char* Adress, PHONE _Phone, Rating _Evaluation)
{
    SetSurame(Surname);
    SetName(Name); 
    SetPatronymic(Patronymic);
    SetBirthday(_Birthday);
    SetAdress(Adress);
    SetPhone(_Phone);
    SetEvaluations(_Evaluation);
}

Student::~Student()
{
    delete[]this->name;
    delete[]this->surname;
    delete[]this->patronymic;
    delete[]this->adress;
}