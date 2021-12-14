#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include "c_UserProfile.h"
void getDate(int& day, int& mounth, int& year);
void createProfiles(int size, c_UserProfile*& arr);
void deleteProfiles(c_UserProfile*& arr);
void countMinors(int size, c_UserProfile* arr, int& amount);
void fillProfiles(int size, c_UserProfile* arr);
void printProfiles(int size, c_UserProfile* arr);
using namespace std;
int main()
{
	c_UserProfile* profiles;
	const int size = 5;
	int amount_minors = 0;
	createProfiles(size, profiles);
	fillProfiles(size, profiles);
	printProfiles(size, profiles);
	countMinors(size, profiles, amount_minors);
	cout << endl << "Amount minors: " << amount_minors << endl;
	deleteProfiles(profiles);
}

void getDate(int& day, int& mounth, int& year)
{
	const time_t t = time(0);
	tm* now = localtime(&t);
	day = now->tm_mday;
	mounth = now->tm_mon + 1;
	year = now->tm_year + 1900;
}

void createProfiles(int size, c_UserProfile*& arr)
{
	arr = new c_UserProfile[size];
}

void deleteProfiles(c_UserProfile*& arr)
{
	delete[] arr;
}

void countMinors(int size, c_UserProfile* arr, int& amount)
{
	int now_day, now_mounth, now_year;
	getDate(now_day, now_mounth, now_year);
	for (int i = 0; i < size; i++)
	{
		if ((now_year - arr[i].getYear()) <= 18) {
			if (now_mounth > arr[i].getMounth()) {
				amount++;
			}
			else if(now_mounth == arr[i].getMounth()) {
				if (now_day < arr[i].getDay()) {
					amount++;
				}
			}
		}
	}
}

void fillProfiles(int size, c_UserProfile* arr)
{
	for (int i = 0; i < size; i++)
	{
		char last_name[30];
		char first_name[30];
		char patronymic[30];
		int day;
		int mounth;
		int year;
		system("cls");
		cout << "Enter last name ";
		gets_s(last_name);
		cout << "Enter fisrt name ";
		gets_s(first_name);
		cout << "Enter patronymic ";
		gets_s(patronymic);
		cout << "Enter date of birth (day mounth year) ";
		cin >> day >> mounth >> year;
		cin.ignore();
		arr[i].setLastName(last_name);
		arr[i].setFirstName(first_name);
		arr[i].setPatronymic(patronymic);
		arr[i].setDay(day);
		arr[i].setMounth(mounth);
		arr[i].setYear(year);
		system("pause");
	}
}

void printProfiles(int size, c_UserProfile* arr)
{
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i].print();
	}
}
