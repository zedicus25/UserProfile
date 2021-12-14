#include "c_UserProfile.h"
#include <iostream>
c_UserProfile::c_UserProfile()
{
	this->last_name = nullptr;
	this->first_name = nullptr;
	this->patronymic = nullptr;
	this->year = 0;
	this->mounth = 0;
	this->day = 0;
}

void c_UserProfile::setLastName(const char* last_name)
{
	this->last_name = new char[strlen(last_name) + 1];
	strcpy_s(this->last_name, strlen(last_name) + 1, last_name);
}

void c_UserProfile::setFirstName(const char* first_name)
{
	this->first_name = new char[strlen(first_name) + 1];
	strcpy_s(this->first_name, strlen(first_name) + 1, first_name);
}

void c_UserProfile::setPatronymic(const char* patronymic)
{
	this->patronymic = new char[strlen(patronymic) + 1];
	strcpy_s(this->patronymic, strlen(patronymic) + 1, patronymic);
}

void c_UserProfile::setYear(int year)
{
	if (year > 0 && year > 1940) {
		this->year = year;
	}
	else {
		std::cout << "Incorrect input\n";
	}
}

void c_UserProfile::setMounth(int mounth)
{
	if (mounth > 0 && mounth <= 12) {
		this->mounth = mounth;
	}
	else {
		std::cout << "Incorrect input\n";
	}
}

void c_UserProfile::setDay(int day)
{
	if (day > 0 && day <= 31) {
		this->day = day;
	}
	else {
		std::cout << "Incorrect input\n";
	}
}

void c_UserProfile::print()
{
	std::cout << this->last_name << " " << this->first_name << " " << this->patronymic << " "
		<< this->day << "/" << this->mounth << "/" << this->year << std::endl;
}


