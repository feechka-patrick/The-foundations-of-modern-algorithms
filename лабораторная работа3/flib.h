#ifndef FLIB_H
# define FLIB_H

#include <iostream>
#include <fstream>
using namespace std;

struct client
{
	client() : null (true) {}
	string fullname;
	string dateofbirth;
	string adress;
	bool null;
};

int ft_strcmp(client ct1, client ct2, int k);
int ft_strcmp(string s1, string s2);

#endif

































