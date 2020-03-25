#pragma once
#include <iostream>
#include <string>
#include "Date.h"

class Ticket
{
private:
	int way_id_ = 0;
	std::string geo_points_ = "";
	std::string fio_ = "";
	Date* date_ = new Date();

	void copy(const Ticket* ticket);
public:
	Ticket();
	Ticket(const int way_id, const std::string& geo_points, const std::string& fio, const Date* date);
	Ticket(const Ticket* ticket);
	~Ticket();

	std::string to_string() const;

	friend std::ostream& operator<<(std::ostream& out, const Ticket* ticket);
	friend std::ostream& operator<<(std::ostream& out, const Ticket ticket);
	friend std::istream& operator>> (std::istream& in, Ticket*& ticket);
	friend std::istream& operator>> (std::istream& in, Ticket& ticket);

	void set_ticket(const int way_id, const std::string& geo_points, const std::string& fio, const Date* date);
	void set_ticket(const Ticket* ticket);

	int get_way_id() const;
	void set_way_id(const int way_id);

	std::string get_geo_points() const;
	void set_geo_points(const std::string& geo_points);

	std::string get_fio() const;
	void set_fio(const std::string& fio);

	Date* get_date() const;
	void set_date(const Date* date);
};
