#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cerr << "Error: Wrong number of arguments!" << std::endl;
	return (0);
}
