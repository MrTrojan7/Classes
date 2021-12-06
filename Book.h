#pragma once
#include <iostream>
class Book
{
private:
	char* author;
	char* name;
	bool is_interesting;
	char* genre;
	char* country;
	int page_count;
	int year_of_publishing;
public:
	Book();
	Book(const char* _author, const char* _name,
		const char* _genre, const char* _country,
		int page_count, bool is_interesting, int year_of_publishing);
	const char* const GetName();
	const char* const GetAuthor();
	const char* const GetGenre();
	const char* const GetCountry();
	const int GetPageCount();
	int GetYearOfPublishing();
	bool IsInteresting();
	void Show();
	~Book();
};

