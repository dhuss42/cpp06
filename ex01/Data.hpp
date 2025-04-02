#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <fstream>

typedef struct s_Data
{
	int			i;
	float		f;
	double		d;
	char		c;
	std::string s;
} Data;

// std::ostream& operator<<(std::ostream& os, const Data& data)
// {
// 	os << "Data struct" << "\n\tint i:\t\t" << data.i << "\n\tfloat f:\t" << data.f << "\n\tdouble d:\t" << data.d << "\n\tchar c:\t\t" << data.c << "\n\tstring s:\t" << data.s;
// 	return (os);
// }

#endif