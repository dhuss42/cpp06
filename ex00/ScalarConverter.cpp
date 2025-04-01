#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	(void) src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
}

// detect type of literal passed
// convert it from str to actual type
// then convert it to the three other data types
// display results below

// if conversion does not make sense or overflows
// -> display message

bool	isInt(std::string str)
{
	bool	isInt = true;
	int		i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

int ScalarConverter::detectType(std::string str)
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

void	ScalarConverter::printType(int type)
{
	switch (type)
	{
		case CHAR:
			std::cout << "Detected Type: CHAR" << std::endl;
			break;
		case INT:
			std::cout << "Detected Type: INT" << std::endl;
			break;
		case FLOAT:
			std::cout << "Detected Type: FLOAT" << std::endl;
			break;
		case DOUBLE:
			std::cout << "Detected Type: DOUBLE" << std::endl;
			break;
		case SPECIALDOUBLE:
			std::cout << "Detected Type: SPECIALDOUBLE" << std::endl;
			break;
		case SPECIALFLOAT:
			std::cout << "Detected Type: SPECIALFLOAT" << std::endl;
			break;
		default:
			std::cout << "Detected Type: INVALID" << std::endl;
			break;
	}
}

double ScalarConverter::doubleConversion(std::string str, int type)
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
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Error: Invalid double input!" << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Error: Double out of range!" << std::endl;
		}
		return (std::numeric_limits<double>::quiet_NaN());
	}
}

double ScalarConverter::floatConversion(std::string str, int type)
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
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Error: Invalid float input!" << std::endl;
		}
		catch (const std::out_of_range& e)
		{
			std::cerr << "Error: Float out of range!" << std::endl;
		}
		return (std::numeric_limits<double>::quiet_NaN());
	}
}

double ScalarConverter::intConversion(std::string str, int type)
{
	try
	{
		return (static_cast<double>(std::stoi(str)));
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: Invalid int input!" << std::endl;
	}
	catch (const std::out_of_range& e)
	{
		std::cerr << "Error: Int out of range!" << std::endl;
	}
	return (std::numeric_limits<double>::quiet_NaN());
}

double ScalarConverter::charConversion(std::string str, int type)
{
	return (static_cast<double>(str[1]));	
}

double ScalarConverter::initialConversion(std::string str, int type)
{
	if (type == CHAR)
		return (charConversion(str, type));
	else if (type == INT)
		return (intConversion(str, type));
	else if (type == FLOAT || type == SPECIALFLOAT)
		return (floatConversion(str, type));
	else if (type == DOUBLE || type == SPECIALDOUBLE)
		return (doubleConversion(str, type));
	return (0);
}

void ScalarConverter::parsing(std::string str, int& type)
{
	if (str.empty())
	{
		std::cerr << "Error: cannot convert Empty string!" << std::endl;
		exit(EXIT_FAILURE);
	}
	type = detectType(str);
	printType(type);
	if (type == INVALID)
	{
		std::cerr << "Error: type is invalid, cannot convert!" << std::endl;
		exit(EXIT_FAILURE);
	}
	return ;
}

void ScalarConverter::convert(std::string str)
{
	double	result;
	int		type;

	parsing(str, type);
	result = initialConversion(str, type);
	std::cout << "result: " << result << std::endl;
	// print all converted values from double 
}





//convert to char   
		// 'c'
	//convert to int
		// 0, -42, 42
	//convert to float
		// 0.0f, -4.2f, 4.2f, -inff, +inff
	//convert to double
		// 0.0, -4,2, 4,2, -inf, +inf, nan

	// static_cast <dest_type> (source)
