#ifndef FLIB_H
# define FLIB_H

#include <iostream>
using namespace std;

typedef struct
{
	string fullname;
	string dateofbirth;
	string adress;
	bool null;
}		client;

int ft_strcmp(client ct1, client ct2, int k);
int ft_strcmp(string s1, string s2);

#endif

































