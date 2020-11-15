#include "flib.h"

struct list
{
	list() : next(NULL) {}
	list(client dat)
	{
		data.fullname = dat.fullname;
		data.dateofbirth = data.dateofbirth;
		data.adress = dat.adress;
		data.null = dat.null;
	}
	client data;
	list *next;
};

class ClientData
{
private:
	list *clients;

public:
	ClientData()
	{
		clients = NULL;
	}
	void read_data(string file) // чтение данных из файла
	{
		ifstream ifs(file);
		while (ifs)
		{
			client newdata;
			string name;

			ifs >> name;
			newdata.fullname += name + ' ';
			ifs >> name;
			newdata.fullname += name + ' ';
			ifs >> name;
			newdata.fullname += name;
			cout << newdata.fullname << endl;
			ifs >> newdata.dateofbirth;
			ifs >> newdata.adress;
			if (newdata.fullname[0] != ' ')
				newdata.null = false;

			ft_list_push_back(newdata);
		}
	}
	void show_current(list *current) //вывод текущей структуры
	{
		if (current->data.null == true)
			cout << "null\n";
		else
		{
			cout << current->data.fullname << " ";
			cout << current->data.dateofbirth << " ";
			cout << current->data.adress << endl;
		}
	}
	void show_data() // вывести все
	{
		list *head;
		head = clients;
		if (head)
		{
			while (head->next)
			{
				show_current(head);
				head = head->next;
			}
		}
		else
			cout << "data empty\n";
	}
	void ft_list_push_front(client data) // добавление в начало списка
	{
		list *second;
		second = new list(data);
		second->next = clients;
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
	}
	void ft_del_find(list *find) // удаление найденного
	{
		if (find == clients)
			ft_list_del_front();
		if (!find->next)
			ft_list_push_back();
		else
		{
			list *next = find->next;
			delete find;
			find = next;
		}
	}
	void ft_list_del_front() // удаление элемента из начала списка
	{
		if (clients)
		{
			list *newnode = clients->next;
			delete clients;
			clients = newnode;
		}
	}
	void ft_list_del_back() // удаление из конца списка
	{
		list *end;
		end = clients;
		while (end->next->next)
			end = end->next;
		delete end->next;
		end->next = NULL;
	}
	~ClientData()
	{
		cout << "\nGooodbyee!\n";
		delete clients;
	}
};

int main(void)
{
	ClientData newdata;
	newdata.read_data("data.txt");
	int change;
	do
	{
		cout << "\nEnter \n1 - for to display the database on the screen\n"
			 << "0 - to exit the program\n";
		cin >> change;
		if (change == 1)
		{
			newdata.show_data();
		}
	} while (change != 0);
}