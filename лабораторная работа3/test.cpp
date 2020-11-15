
// проверяем односвязный список

#include <iostream>
using namespace std;

struct client
{
	client() : null (true) {}
	client(string n, string d, string a) : 
		fullname(n), dateofbirth(d), adress(a), null(false) {}
	string fullname;
	string dateofbirth;
	string adress;
	bool null;
};

struct list
{
	list() : next(NULL) {}
	list(client dat) : data(dat), next(NULL) {}
	client	data;
	list*	next;
};

class ClientData
{
private:
	list *clients;
public:
	ClientData()
	{
		clients = new list();
	}
};

int main ()
{
	ClientData example;

}