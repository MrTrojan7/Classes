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
    vector<int> mas1;
    vector<int> mas2;
    vector<int> mas3;
    Rating _evaluations;
    void SetBirthday(Date _birthday);
    void SetPatronymic(const char* patronymic);

public:

    void SetSurame(const char* surname);
    void SetName(const char* name);

    void SetAdress(const char* adress);
    void SetPhone(PHONE _phone);
    void SetEvaluations (Rating _evaluation);
    char* GetSurname() const;
    char* GetName() const;
    char* GetPatronymic() const;
    void GetBirthday(const Date date) const;
    char* GetAdress() const;
    void GetEvaluations(const vector <int> mas) const;
    int GetPhone(const int phone) const;
    bool GetCheckZero(int val1, int val2, int val3) const;

    void Show();
    Student();
    Student(const char* Surname, const char* Name, 
        const char* Patronymic, Date _Birthday, 
        const char* Adress, PHONE Phone, Rating _Evaluation);
    Student(const Student& student);
    ~Student();
};



