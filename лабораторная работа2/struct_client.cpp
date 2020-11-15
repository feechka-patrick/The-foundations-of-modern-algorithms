#include <iostream>
#include <fstream>
#include "flib.h"

#define filename "data.txt"
#define max_size 4

using namespace std;

class ClientData
{
private:
	client *clients;

public:
	ClientData()
	{
		clients = new client[max_size];

		for (int i = 0; i < max_size; i++)
			clients[i].null = true;
	}
	client *read_data(string file) // чтение данных из файла
	{
		ifstream ifs(file);
		int i = 0;

		while (ifs && i < max_size)
		{
			string name;
			ifs >> name;
			clients[i].fullname += name + ' ';
			ifs >> name;
			clients[i].fullname += name + ' ';
			ifs >> name;
			clients[i].fullname += name;
			ifs >> clients[i].dateofbirth;
			ifs >> clients[i].adress;
			if (clients[i].fullname[0] != ' ')
				clients[i].null = false;
			i++;
		}
		return clients;
	}

	void write_data(string file) // запись в файл
	{
		ofstream ifs(file);
		int i = 0;

		string textfile;
		while (i < max_size)
		{
			textfile += clients[i].fullname + ' ';
			textfile += clients[i].dateofbirth + ' ';
			textfile += clients[i].adress + '\n';
			i++;
		}
		ifs << textfile;
	}

	void show_index(int index) //вывод данных по индексу
	{
		if (clients[index].null == true)
			cout << "null\n";
		else
		{
			cout << clients[index].fullname << " ";
			cout << clients[index].dateofbirth << " ";
			cout << clients[index].adress << endl;
		}
	}
	void show_data() // вывести все
	{
		for (int i = 0; i < max_size; i++)
			show_index(i);
	}

	void read_index(int index) // чтение одной структуры с клавиатуры
	{
		if (index < max_size)
		{
			string name;
			cin >> clients[index].fullname;
			cin >> name;
			clients[index].fullname += ' ' + name;
			cin >> name;
			clients[index].fullname += ' ' + name;
			cin >> clients[index].dateofbirth;
			cin >> clients[index].adress;
			clients[index].null = false;
		}
	}

	void clean_data(int i) // очищение одной ячейки
	{
		if (i >= 0 && i < max_size)
		{
			clients[i].null = true;
		}
	}

	int search_empty() // поиск пустой ячейки
	{
		for (int i = 0; i < max_size; i++)
		{
			if (clients[i].null)
				return (i);
		}
		return (-1);
	}

	void sorted_up(int k) // сортировка по возрастанию
	{
		for (int i = 0; i < max_size - 1; i++)
		{
			for (int j = 0; j < max_size - i - 1; j++)
			{
				if (ft_strcmp(clients[j], clients[j + 1], k) > 0 || clients[j].null) // если порядок неправильный
				{
					client buf = clients[j + 1];
					clients[j + 1] = clients[j];
					clients[j] = buf;
				}
			}
		}
	}

	void sorted_down(int k) // сортировка по убыванию
	{
		for (int i = 0; i < max_size - 1; i++)
		{
			for (int j = 0; j < max_size - i - 1; j++)
			{
				if (ft_strcmp(clients[j], clients[j + 1], k) < 0) // если порядок неправильный
				{
					client buf = clients[j + 1];
					clients[j + 1] = clients[j];
					clients[j] = buf;
				}
			}
		}
	}

	int search_min(int k) // поиск минимального
	{
		client min = clients[0];
		int index = 0;

		for (int i = 1; i < max_size; i++)
		{
			if (ft_strcmp(min, clients[i], k) > 0)
			{
				//cout << min.fullname << " > " << clients[i].fullname << endl;
				min = clients[i];
				index = i;
			}
		}
		return index;
	}

	int search_nearest(string value, int k)
	{
		int left = 0;
		int right = max_size - 1;

		int index = 0;
		sorted_up(k);
		while (left <= right)
		{
			index = (right + left) / 2;
			if (ft_strcmp(clients[index].fullname, value) == 0)
				return (index);
			else if (ft_strcmp(clients[index].fullname, value) > 0)
				right = index - 1;
			else
				left = index + 1; 
		}
		return (index + 1);
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
		if (change == 1)
			newdata.show_data();
		if (change == 2)
		{
			cout << "enter index: ";
			cin >> index;
			newdata.show_index(index);
		}
		if (change == 3)
		{
			cout << "enter index for clean: ";
			cin >> index;
			newdata.clean_data(index);	
		}
		if (change == 4)
			cout << "index empty cell: " << newdata.search_empty();
		if (change == 5)
		{
			cout << "enter index: ";
			cin >> index;
			cout << "--> ";
			newdata.read_index(index);
		}
		if (change == 6)
		{
			string value;
			cout << "the number of the field structure (1 - 3): ";
			cin >> index;
			cout << "field value: ";
			cin >> value;
			newdata.show_index(newdata.search_nearest(value, index));
		}
		if (change == 7)
		{
			cout << "the number of the field structure (1 - 3): ";
			cin >> index;
			cout << "minimum structure of field " << index << " : ";
			newdata.show_index(newdata.search_min(index));
		}
		if (change == 8)
		{
			cout << "the number of the field structure (1 - 3): ";
			cin >> index;
			newdata.sorted_up(index);
			cout << "the structure sorted\n";
		}
		if (change == 9)
		{
			cout << "the number of the field structure (1 - 3): ";
			cin >> index;
			newdata.sorted_down(index);
			cout << "the structure sorted\n";
		}
		if (change == 10)
		{
			string file;
			cout << "enter filename: ";
			cin >> file;
			newdata.read_data(file);
			cout << "database read\n";
		}
		if (change == 11)
		{
			string file;
			cout << "enter filename: ";
			cin >> file;
			newdata.write_data(file);
			cout << "the database is recorded\n";
		}
	} while (change != 0);
	cout << "goodbye";
}