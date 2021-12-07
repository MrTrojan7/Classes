#include "Book.h"
using namespace std;
Book::Book()
{
	this->author = new char[100];
	this->name = new char[100];
	this->genre = new char[100];
	this->country = new char[100];
	this->is_interesting = rand() % 2;
	this->page_count = rand() % (2500 - 1000) + 1000;
	this->year_of_publishing = rand() % (2021 - 1950) + 1950;
	strcpy_s(author, 99, "Stiven Prata");
	strcpy_s(name, 99, "Programming on C++");
	strcpy_s(genre, 99, "Programming");
	strcpy_s(country, 99, "USA");
}

Book::Book(const char* author, const char* name,
	const char* genre, const char* country,
	int page_count, bool is_interesting,
	int year_of_publishing)
{
	this->author = new char[100];
	this->name = new char[100];
	this->genre = new char[100];
	this->country = new char[100];
	this->is_interesting = is_interesting;
	this->page_count = page_count;
	this->year_of_publishing = year_of_publishing;
	strcpy_s(this->author, 99, author);
	strcpy_s(this->name, 99, name);
	strcpy_s(this->genre, 99, genre);
	strcpy_s(this->country, 99, country);
}

const char* const Book::GetName()
{
	return name;
}
const char* const Book::GetAuthor()
{
	return author;
}

const char* const Book::GetGenre()
{
	return genre;
}

const char* const Book::GetCountry()
{
	return country;
}

const int Book::GetPageCount()
{
	return page_count;
}

int Book::GetYearOfPublishing()
{
	return year_of_publishing;
}

bool Book::IsInteresting()
{
	return is_interesting;
}

void Book::Show()
{
	cout << "Author: " << this->author << "\n";
	cout << "Name: " << this->name << "\n";
	cout << "Genre: " << this->genre << "\n";
	cout << "Country: " << this->country << "\n";
	cout << "Year of publishing: " << this->year_of_publishing << "\n";
	cout << "Page Count: " << this->page_count << "\n";
	this->is_interesting ? cout << "Interesting\n" : cout << "Not interesting\n";
}

Book::~Book()
{
	delete[] author;
	delete[] name;
	delete[] genre;
	delete[] country;
}