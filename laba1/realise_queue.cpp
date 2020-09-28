#include <iostream>
#include <locale>

int SIZE;
using namespace std;

class Queue
{
public:
	int* line;
    int begin;
	int end;
public:
    Queue(int size)
	{
		begin = 0;
		end = 0;
		line = new int[size];
	}
	void show()
	{
		for (int i = begin; i < end + 1; i++)
		{
			cout << line[i] << " ";
		}
		cout << "\n";
	}
	int pop()
	{
		if (begin == end)
		{
			cout << "Line is empty!\n";
			return (-1);
		}
		else
		{
			int el = line[begin];
        	begin = (begin + 1) % SIZE;
			return el;	
		}
	}
	void push(int element)
	{
		if (begin == (end + 1) % SIZE)
		{
			cout << "Line is full!\n";
			return;
		}
		line[end] = element;
        end = (end + 1) % SIZE;
	}
    ~Queue()
	{
		cout << "I am free!\n";
		delete[] line;
	}
};
int main()
{
	SIZE = 3;
	setlocale(LC_ALL, "Russian");
	cout << "Enter size of line: ";
	cin >> SIZE;
	SIZE++;
    Queue line(SIZE);
	while (true)
	{
		int choose;
		cout << "For push enter 1, for pop - 2, for exit enter 3: ";
		cin >> choose;
		if (choose == 1)
		{
			cout << "Enter element: ";
			int element;
			cin >> element;
		    line.push(element);
		}
		if (choose == 2)
		{
            int element = line.pop();
            if (element != -1)
			    cout << "Element: " << element << "\n";
		}
		if (choose == 3)
			return (0);
	}
}
