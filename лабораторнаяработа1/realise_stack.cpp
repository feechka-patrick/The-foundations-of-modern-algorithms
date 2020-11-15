#include <iostream>
#include <locale>

int SIZE;
using namespace std;

class Stack
{
public:
	int* stack;
	int current;
public:
	Stack(int size)
	{
		current = -1;
		stack = new int[size];
	}
	int pop()
	{
		if (current == -1)
		{
			cout << "Stack is empty!\n";
			return (-1);
		}
		current--;
		return	stack[current + 1];
	}
	void push(int element)
	{
		if (current == SIZE - 1)
		{
			cout << "Stack is full!\n";
			return;
		}
		stack[current + 1] = element;
		current++;
	}
	~Stack()
	{
		cout << "I am free!\n";
		delete[] stack;
	}
};
int main()
{
	SIZE = 3;
	setlocale(LC_ALL, "Russian");
	cout << "Enter size of stack: ";
	cin >> SIZE;
	Stack stack(SIZE);
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
			stack.push(element);
		}
		if (choose == 2)
		{
			int element = stack.pop();
			if (element != -1)
				cout << "Element: " << element << "\n";
		}
		if (choose == 3)
			return (0);
	}
}