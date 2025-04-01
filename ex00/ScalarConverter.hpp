#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string.h>
#include <sstream>
#include <limits.h>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		enum e_scalar
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			SPECIALDOUBLE,
			SPECIALFLOAT,
			INVALID,
		};

		static double	charConversion(std::string str, int type);
		static double	intConversion(std::string str, int type);
		static double	floatConversion(std::string str, int type);
		static double	doubleConversion(std::string str, int type);
		static int		detectType(std::string str);
		static void		printType(int type);
		static double	initialConversion(std::string str, int type);
		static void 	parsing(std::string str, int& type);
		static void		convert(std::string str);

};


#endif