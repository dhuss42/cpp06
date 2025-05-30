/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:48:42 by dhuss             #+#    #+#             */
/*   Updated: 2025/04/28 17:02:29 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*----------------------*/
/* Constructor			*/
/*----------------------*/
ScalarConverter::ScalarConverter()
{
}

/*----------------------*/
/* Copy Constructor		*/
/*----------------------*/
ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void) src;
}

/*----------------------*/
/* Assignment Operator	*/
/*----------------------*/
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return (*this);
}

/*----------------------*/
/* Destructor			*/
/*----------------------*/
ScalarConverter::~ScalarConverter()
{
}

//------------print functons-------------//

void	printInt(double value)
{
	int num;

	std::cout << "int:\t";
	if (value >= INT_MIN && value <= INT_MAX && static_cast<int>(value) == value)
		num = static_cast<int>(value);
	else
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << num << std::endl;
}

void	printChar(double value)
{
	char c;
	std::cout << "char:\t";
	if (value >= 0 && value <= 127 && static_cast<char>(value) == value)
		c = static_cast<char>(value);
	else
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (isprint(c))
		std::cout << "\'" << c << "'";
	else
	{
		std::cout << "Non displayable" << std::endl;
		return ;
	}
	std::cout << std::endl;
}

void	printFloat(double value)
{
	float	num;

	std::cout << "float:\t";
	if (std::isnan(value))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (value >= -std::numeric_limits<float>::max() && value <= std::numeric_limits<float>::max())
		num = static_cast<float>(value);
	else if (value == std::numeric_limits<float>::infinity() || value == -std::numeric_limits<float>::infinity())
		num = static_cast<float>(value);
	else
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (num == static_cast<int>(num))
		std::cout << num << ".0f" << std::endl;
	else
		std::cout << num << "f" << std::endl;
}

void	printDouble(double value)
{
	std::cout << "double:\t";
	if (value == static_cast<int>(value))
		std::cout << value << ".0" << std::endl;
	else
		std::cout << value << std::endl;
}

void	printValues(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

//----------------------initial conversion------------------------//

double	doubleConversion(std::string str)
{
	if (str == "+inf")
		return (static_cast<double>(std::numeric_limits<double>::infinity()));
	else if (str == "-inf")
		return (static_cast<double>(-std::numeric_limits<double>::infinity()));
	else if (str == "nan")
		return (std::numeric_limits<double>::quiet_NaN());
	else
	{
		try
		{
			return (std::stod(str));
		}
		catch (const std::invalid_argument& e){}
		catch (const std::out_of_range& e){}
		return (std::numeric_limits<double>::quiet_NaN());
	}
}

double	floatConversion(std::string str)
{
	if (str == "+inff")
		return (static_cast<double>(std::numeric_limits<float>::infinity()));
	else if (str == "-inff")
		return (static_cast<double>(-std::numeric_limits<float>::infinity()));
	else if (str == "nanf")
		return (std::numeric_limits<double>::quiet_NaN());
	else
	{
		try
		{
			return (static_cast<double>(std::stof(str)));
		}
		catch (const std::invalid_argument& e){}
		catch (const std::out_of_range& e){}
		return (std::numeric_limits<double>::quiet_NaN());
	}
}

double	intConversion(std::string str)
{
	try
	{
		return (static_cast<double>(std::stoi(str)));
	}
	catch (const std::invalid_argument& e){}
	catch (const std::out_of_range& e){}
	return (std::numeric_limits<double>::quiet_NaN());
}

double	charConversion(std::string str)
{
	return (static_cast<double>(str[1]));
}

double	initialConversion(std::string str, int type)
{
	if (type == CHAR)
		return (charConversion(str));
	else if (type == INT)
		return (intConversion(str));
	else if (type == FLOAT || type == SPECIALFLOAT)
		return (floatConversion(str));
	else if (type == DOUBLE || type == SPECIALDOUBLE)
		return (doubleConversion(str));
	return (0);
}

//----------------------parsing------------------------//

bool	isInt(std::string str)
{
	size_t		i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

int	detectType(std::string str)
{
	if (str.length() == 3 && str[0] == '\'' && str[2] == '\'' && isprint(str[1]))
		return (CHAR);
	else if (str == "+inf" || str == "-inf" || str == "nan")
		return (SPECIALDOUBLE);
	else if (str == "+inff" || str == "-inff" || str == "nanf")
		return (SPECIALFLOAT);
	else if (isInt(str))
		return (INT);
	else if (str.back() == 'f' && str.find('.') != std::string::npos)
		return (FLOAT);
	else if (str.find('.') != std::string::npos)
		return (DOUBLE);
	return (INVALID);
}

/*------------------------------------------------------------------*/
/* regex pattern													*/
/* 		^		match must start at the very beginning of string	*/
/* 		[-+]?	Zero or one occurance of +, -						*/
/* 		[0-9]+	One or more digits									*/
/* 		\\.		. character escaped									*/
/* 		[0-9]*	zero or more digits after .							*/
/* 		()		groups together into one unit						*/
/* 		?		makes that unit optional							*/
/* 		f		the character f										*/
/* 		$		end of the string									*/
/*------------------------------------------------------------------*/
bool	isValidFloatFormat(const std::string& str)
{
	std::regex floatPattern("^[-+]?[0-9]+\\.[0-9]*([eE][-+]?[0-9]+)?f$");
	return (std::regex_match(str, floatPattern));
}

bool	isValidDoubleFormat(const std::string& str)
{
	std::regex doublePattern("^[-+]?[0-9]+\\.[0-9]*([eE][-+]?[0-9]+)?$");
	return (std::regex_match(str, doublePattern));
}

void	parsing(std::string str, int& type)
{
	if (str.empty())
	{
		std::cerr << "Error: cannot convert Empty string!" << std::endl;
		exit(EXIT_FAILURE);
	}
	type = detectType(str);
	if (type == FLOAT && !isValidFloatFormat(str))
		type = INVALID;
	if (type == DOUBLE && !isValidDoubleFormat(str))
		type = INVALID;
	if (type == INVALID)
	{
		std::cerr << "Error: type is invalid, cannot convert!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

//----------------------member function------------------------//
/*--------------------------*/
/* convert function			*/
/*--------------------------*/
void ScalarConverter::convert(std::string str)
{
	double	result;
	int		type;

	parsing(str, type);
	result = initialConversion(str, type);
	printValues(result);
}
