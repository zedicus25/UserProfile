#pragma once
class c_UserProfile
{
private:
	char* last_name;
	char* first_name;
	char* patronymic;
	int year;
	int mounth;
	int day;
public:
	c_UserProfile();

	//sets
	void setLastName(const char* last_name);
	void setFirstName(const char* first_name);
	void setPatronymicName(const char* patronymic);
	void setYear(int year);
	void setMounth(int mounth);
	void setDay(int day);

	//gets
	inline char* getLastName() const {
		return this->last_name;
	}
	inline char* getFirstName() const {
		return this->first_name;
	}
	inline char* getPatronymic() const {
		return this->patronymic;
	}
	inline int getYear() const {
		this->year;
	}
	inline int getMounth() const {
		this->mounth;
	}
	inline int getDay() const {
		this->day;
	}

	void print();
};

