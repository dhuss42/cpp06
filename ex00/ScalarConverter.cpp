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

int	ScalarConverter::detectType(std::string str)
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
	if (type == INVALID)
	{
		std::cerr << "Error: type is invalid, cannot convert!" << std::endl;
		exit(EXIT_FAILURE);
	}
	return ;
}

void	printInt(double value)
{
	int num;

	std::cout << "int:\t";
	if (value > INT_MIN && value < INT_MAX)
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
	if (value >= 0 && value <= 127)
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

void printValues(double value)
{
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

void ScalarConverter::convert(std::string str)
{
	double	result;
	int		type;

	parsing(str, type);
	result = initialConversion(str, type);
	printValues(result);
}
