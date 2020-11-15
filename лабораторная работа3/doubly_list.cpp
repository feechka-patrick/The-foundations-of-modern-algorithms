#include "flib.h"

struct list
{
	list() : next(NULL), after(NULL) {}
	list(client dat) : data(dat), after(NULL), next(NULL) {}
	client	data;
	list*	next;
	list*	after;
};

class ClientData
{
private:
	list *clients;
public:
	void ft_list_push_front(client data) // добавление в начало списка
	{
		list *second;
		second = new list(data);
		second->next = clients;
		clients->after = second;
		clients = second;
	}
	void ft_list_push_back(client data) // добавление в конец списка
	{
		list *search;
		search = clients;
		if (!search)
		{
			search = new list(data);
			clients = search;
		}
		else
		{
			while (search->next)
				search = search->next;
			search->next = new list(data);
			search->next->after = search;
		}
	}
	list *ft_list_find(client data_ref, int k) // поиск элемента по заначению поля
	{
		list *begin_list = clients;
		while (begin_list)
		{
			if (ft_strcmp(begin_list->data, data_ref, k) == 0)
				return (begin_list);
			begin_list = begin_list->next;
		}
		return (0);
	}
	void ft_del_after_find(list *find) // удаление после найденного
	{
		list *after_after_find = find->next->next;
		delete find->next;
		find->next = after_after_find;
		after_after_find->after = find;
	}
	void ft_del_find(list *find) // удаление найденного
	{
		list *next = find->next;
		next->after = find->after;
		delete find;
		find = next;
	}
	void ft_list_del_front() // удаление элемента из начала списка
	{
		if (clients)
		{
			list* newnode = clients->next;
			newnode->after = NULL;
			delete clients;
			clients = newnode;
		}
	}
	void ft_list_del_back() // удаление из конца списка
	{
		list *end;
		end = clients;
		while(end->next->next)
			end = end->next;
		delete end->next;
		end->next = NULL;
	}
	~ClientData() // деструктор
	{
		cout << "\nGooodbyee!\n";
		delete clients;
	}
};

int main(void)
{
	ClientData newdata;

	int change;
	int index;
	do
	{
		cout << "\nEnter \n1 - for to display the database on the screen\n"
			 << "2 - to display a cell N\n"
			 << "3 - to clear a cell number N\n"
			 << "4 - to print the index of the first empty cell\n"
			 << "5 - to write data to cell N\n"
			 << "6 - to search an array of structures for an element with the specified field value or with the closest value to it\n"
			 << "7 - search for the minimum\n"
			 << "8 - sorting the database in ascending order\n"
			 << "9 - sorting the database in descending order\n"
			 << "10 - reading a database from a file\n"
			 << "11 - write the database to a file\n"
			 << "0 - to exit the program\n"
			 << "--> ";
		cin >> change;
	} while (change != 0);
	cout << "goodbye";
}