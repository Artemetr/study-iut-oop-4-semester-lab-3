#include <art-cpp.h>
#include <iostream>
#include "Date.h"
#include "Ticket.h"

using namespace art::addons;

void create(List<Ticket*>* list)
{
	list->append(new Ticket());
	std::cin >> *(*list)[list->length() - 1];
}

void edit(List<Ticket*>* list, const int index)
{
	std::cin >> *(*list)[index];
}

void del(List<Ticket*>* list, const int index)
{
	list->del(index);
}

void remove(List<Ticket*>* list)
{
	list->clear();
}

void show_ticket(List<Ticket*>* list, const int index)
{
	std::cout << "\n[[[--- " + std::to_string(index) + " ---]]]\n";
	std::cout << (*list)[index];
}

void show_all(List<Ticket*>* list)
{
	for(int i = 0; i < list->length(); i++)
	{
		show_ticket(list, i);
	}
}

int input_number(List<Ticket*>* list)
{
	int number;
	std::cout << "Count of ticket: " + std::to_string(list->length()) + "\n";
	std::cout << "Input number of ticket: ";
	std::cin >> number;
	if (number < 0 || number >= list->length())
	{
		std::cout << "Ticket has not been found\n";
		return  -1;
	}
	else
	{
		return number;
	}
}

int input_way_id()
{
	int number;
	std::cout << "Input way id: ";
	std::cin >> number;
	return number;
}

Date* input_date()
{
	Date* date = new Date();
	std::cout << "Input date: \n";
	std::cin >> date;
	return date;
}

int input_command()
{
	int command;
	std::cout << "Input command (5 - help): ";
	std::cin >> command;
	return command;
}

void show_main_help()
{
	std::cout << "Commands:\n * 0 - exit;\n * 1 - create;\n * 2 - edit;\n * 3 - delete;\n * 4 - show;\n * 5 - help;\n";
}

void show_delete_help()
{
	std::cout << "Commands:\n * 0 - cancel;\n * 1 - by number;\n * 2 - all;\n";
}

void show_filter_help()
{
	std::cout << "Commands:\n * 0 - cancel;\n * 1 - by number;\n * 2 - by way id;\n * 3 - by date;\n * 4 - all;\n";
}

void edit_controller(List<Ticket*>* list)
{
	const int number = input_number(list);
	if (number == -1)
	{
		return;
	}
	edit(list, number);
}

void delete_controller(List<Ticket*>* list)
{
	int number;
	show_delete_help();
	while (true)
	{
		switch (input_command())
		{
		case 0:
			return;
			break;
		case 1:
			number = input_number(list);
			if (number == -1)
			{
				return;
			}
			del(list, number);
			return;
			break;
		case 2:
			remove(list);
			return;
			break;
		default:
			show_delete_help();
			break;
		}
	}
}

void filter_controller(List<Ticket*>* list)
{
	int number;
	Date* date = new Date();
	show_filter_help();
	while (true)
	{
		switch (input_command())
		{
		case 0:
			return;
			break;
		case 1:
			number = input_number(list);
			if (number == -1)
			{
				return;
			}
			show_ticket(list, number);
			return;
			break;
		case 2:
			number = input_way_id();
			if (number == -1)
			{
				return;
			}
			std::cout << *(filter([number](const Ticket * ticket) {return ticket->get_way_id() == number; }, list));
			return;
			break;
		case 3:
			date = input_date();
			std::cout << *(filter([date](const Ticket * ticket) {return ticket->get_date()->to_int() == date->to_int(); }, list));
			return;
			break;
		case 4:
			show_all(list);
			return;
			break;
		default:
			show_filter_help();
			break;
		}
	}
}

void main_controller(List<Ticket*>* list)
{
	show_main_help();
	while(true)
	{
		switch (input_command())
		{
		case 0:
			return;
			break;
		case 1:
			create(list);
			break;
		case 2:
			edit_controller(list);
			break;
		case 3:
			delete_controller(list);
			break;
		case 4:
			filter_controller(list);
			break;
		default:
			show_main_help();
			break;
		}
	}
}

void main()
{
	List<Ticket*>* list = new List<Ticket*>();
	main_controller(list);
}


