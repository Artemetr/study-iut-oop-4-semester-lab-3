#pragma once
#include <iostream>
#include <string>

class Date
{
private:
	int year_;
	int month_;
	int day_;
	void copy(const Date* date);
public:
	Date();
	Date(const int year, const int month, const int day);
	Date(const Date* date);
	~Date();

	std::string to_string() const;
	int to_int() const;

	friend bool operator== (const Date& date1, const Date& date2);
	friend bool operator!= (const Date& date1, const Date& date2);
	friend bool operator>  (const Date& date1, const Date& date2);
	friend bool operator>= (const Date& date1, const Date& date2);
	friend bool operator<  (const Date& date1, const Date& date2);
	friend bool operator<= (const Date& date1, const Date& date2);

	friend std::ostream& operator<<(std::ostream& out, const Date& date);
	friend std::istream& operator>> (std::istream& in, Date*& date);

	void set_date(const int year, const int month, const int day);
	void set_date(const Date* date);

	int get_year() const;
	void set_year(const int year);

	int get_month() const;
	void set_month(const int month);

	int get_day() const;
	void set_day(const int day);
};

