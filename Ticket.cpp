#include "Ticket.h"


void Ticket::copy(const Ticket* ticket)
{
	set_way_id(ticket->get_way_id());
	set_geo_points(ticket->get_geo_points());
	set_fio(ticket->get_fio());
	set_date(get_date());
}

Ticket::Ticket()
{
}

Ticket::Ticket(const int way_id, const std::string& geo_points, const std::string& fio, const Date* date)
{
	set_ticket(way_id, geo_points, fio, date);
}

Ticket::Ticket(const Ticket* ticket)
{
	copy(ticket);
}


Ticket::~Ticket()
{
	delete[] date_;
}

std::string Ticket::to_string() const
{
	std::string result;
	result.append("========Ticket========\nWay id: ");
	result.append(std::to_string(get_way_id()));
	result.append("\nGeo points: ");
	result.append(get_geo_points());
	result.append("\nFIO: ");
	result.append(get_fio());
	result.append("\nDate: ");
	result.append(get_date()->to_string());
	result.append("\n======================\n");
	return result;
}

void Ticket::set_ticket(const int way_id, const std::string& geo_points, const std::string& fio, const Date* date)
{
	set_way_id(way_id);
	set_geo_points(geo_points);
	set_fio(fio);
	set_date(date);
}

void Ticket::set_ticket(const Ticket* ticket)
{
	copy(ticket);
}

int Ticket::get_way_id() const
{
	return way_id_;
}

void Ticket::set_way_id(const int way_id)
{
	if(way_id < 1)
	{
		throw "ErrorValue: invalid way id";
	}
	way_id_ = way_id;
}

std::string Ticket::get_geo_points() const
{
	return geo_points_;
}

void Ticket::set_geo_points(const std::string& geo_points)
{
	geo_points_ = geo_points;
}

std::string Ticket::get_fio() const
{
	return fio_;
}

void Ticket::set_fio(const std::string& fio)
{
	fio_ = fio;
}

Date* Ticket::get_date() const
{
	return date_;
}

void Ticket::set_date(const Date* date)
{
	date_->set_date(date);
}

std::ostream& operator<<(std::ostream& out, const Ticket* ticket)
{
	out << ticket->to_string();
	return out;
}

std::ostream& operator<<(std::ostream& out, const Ticket ticket)
{
	out << ticket.to_string();
	return out;
}

std::istream& operator>>(std::istream& in, Ticket*& ticket)
{
	int way_id;
	std::string geo_points;
	std::string fio;
	Date* date = new Date();
	
	std::cout << "========Edit ticket========\nWay id: ";
	in >> way_id;
	std::cout << "Geo points: ";
	in.ignore(256, '\n');
	std::getline(in, geo_points);
	std::cout << "FIO: ";
	std::getline(in, fio);
	std::cout << "Date: \n";
	in >> date;
	std::cout << "======================\n";

	ticket->set_ticket(way_id, geo_points, fio, date);
	
	return in;
}

std::istream& operator>>(std::istream& in, Ticket& ticket)
{
	int way_id;
	std::string geo_points;
	std::string fio;
	Date* date = new Date();

	std::cout << "========Edit ticket========\nWay id: ";
	in >> way_id;
	std::cout << "Geo points: ";
	in.ignore(256, '\n');
	std::getline(in, geo_points);
	std::cout << "FIO: ";
	std::getline(in, fio);
	std::cout << "Date: \n";
	in >> date;
	std::cout << "======================\n";

	ticket.set_ticket(way_id, geo_points, fio, date);

	return in;
}
