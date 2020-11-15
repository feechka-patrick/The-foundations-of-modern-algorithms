#include "flib.h"
#include <iostream>

int ft_strcmp(client ct1, client ct2, int k)
{
	string s1, s2;

	if (ct1.null || ct2.null)
		return (0);
	if (k == 1)
	{
		s1 = ct1.fullname;
		s2 = ct2.fullname;
	}
	else if (k == 2)
	{
		s1 = ct1.dateofbirth;
		s2 = ct2.dateofbirth;
	}
	else if (k == 3)
	{
		s1 = ct1.adress;
		s2 = ct2.adress;
	}

	return (ft_strcmp(s1, s2));
}

int ft_strcmp(string s1, string s2)
{
	int i = 0;
	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	//cout << s1[i] << " - " << s2[i] << endl;
	return (s1[i] - s2[i]);
}