#include "Date.h"


void Date::copy(const Date* date)
{
	set_year(date->get_year());
	set_month(date->get_month());
	set_day(date->get_day());
}

Date::Date()
{
	set_year(1970);
	set_month(1);
	set_day(1);
}

Date::Date(const int year, const int month, const int day)
{
	set_date(year, month, day);
}

Date::Date(const Date* date)
{
	copy(date);
}


Date::~Date()
{
}

std::string Date::to_string() const
{
	std::string result;
	result.append(std::to_string(get_year()));
	result.append("-");
	result.append(std::to_string(get_month()));
	result.append("-");
	result.append(std::to_string(get_day()));
	return result;
}

int Date::to_int() const
{
	return get_year() * 10000 + get_month() * 100 + get_day();
}

void Date::set_date(const int year, const int month, const int day)
{
	set_year(year);
	set_month(month);
	set_day(day);
}

void Date::set_date(const Date* date)
{
	copy(date);
}

int Date::get_year() const
{
	return year_;
}

void Date::set_year(const int year)
{
	year_ = year;
}

int Date::get_month() const
{
	return month_;
}

void Date::set_month(const int month)
{
	if(month < 1 || month > 12)
	{
		throw "ErrorValue: invalid month";
	}
	month_ = month;
}

int Date::get_day() const
{
	return day_;
}

void Date::set_day(const int day)
{
	if (day < 1 || day > 31)
	{
		throw "ErrorValue: invalid day";
	}
	day_ = day;
}

bool operator==(const Date& date1, const Date& date2)
{
	return date1.to_int() == date2.to_int();
}

bool operator!=(const Date& date1, const Date& date2)
{
	return !(date1 == date2);
}

bool operator>(const Date& date1, const Date& date2)
{
	return date1.to_int() > date2.to_int();
}

bool operator>=(const Date& date1, const Date& date2)
{
	return date1.to_int() >= date2.to_int();
}

bool operator<(const Date& date1, const Date& date2)
{
	return date1.to_int() < date2.to_int();
}

bool operator<=(const Date& date1, const Date& date2)
{
	return date1.to_int() <= date2.to_int();
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << date.to_string();
	return out;
}

std::istream& operator>>(std::istream& in, Date*& date)
{
	int year;
	int month;
	int day;

	std::cout << "=====Date====\nYear: ";
	in >> year;
	std::cout << "Month: ";
	in >> month;
	std::cout << "Day: ";
	in >> day;
	std::cout << "=============\n";

	date->set_year(year);
	date->set_month(month);
	date->set_day(day);

	return in;
}
