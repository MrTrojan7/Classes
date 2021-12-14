#pragma once
#include "AllLibraries.h"
class Date
{
public:
    int day;
    int month;
    int year;
};
class PHONE
{
public:
    int mob;
    int home;
    int work;
};

class Rating
{
public:
    vector<int> mas1;
    vector<int> mas2;
    vector<int> mas3;
    int ev1;
    int ev2;
    int ev3;
};

class Student
{
private:
    char* surname;
    char* name;
    char* patronymic;
    Date birthday;
    char* adress;
    PHONE phone;
    Rating evaluation;

public:

    void SetSurame(char* surname);
    void SetName(char* name);
    void SetPatronymic(char* patronymic);
    Date SetBirthday(Date _birthday);
    void SetAdress(char* adress);
    PHONE SetPhone(PHONE _phone);
    Rating SetEvaluations (Rating _evaluation);
    const char* const GetSurname() const;
    const char* const GetName() const;
    const char* const GetPatronymic() const;
    Date GetBirthday() const;
    const char* const GetAdress() const;
    PHONE GetPhone() const;
    void Show();
    Student();
    Student(const char* Surname, char* Name, char* Patronymic, Date _Birthday, char* Adress, PHONE Phone, Rating _Evaluation);
    ~Student();
};



