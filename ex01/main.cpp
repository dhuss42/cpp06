// when you serialize an object, 
// you are essentially flattening its data into a stream of bytes 
// (often stored in a file or sent over a network). Later, deserialization 
// reconstructs the object by reading those bytes back and restoring the original values.

// Think of it as "saving the state of an object as raw bytes" 
// and later "rebuilding the object from those bytes."

#include "Serialize.hpp"

int	main(void)
{
	Data data = {5, 42.2, 5000, 'Z', "test"};

	std::cout << "\033[34m[----------Tests----------]\033[37m" << std::endl;
	std::cout << "\033[33m- Initial Data of struct\033[37m" << std::endl;
	std::cout << "Data struct" 
				<< "\n\tint i:\t\t" << data.i 
				<< "\n\tfloat f:\t" << data.f 
				<< "\n\tdouble d:\t" << data.d 
				<< "\n\tchar c:\t\t" << data.c 
				<< "\n\tstring s:\t" << data.s 
				<< "\n\tAddress: \t" << &data
				<< std::endl;

	std::cout << "\033[33m- Serialized Data Address\033[37m" << std::endl;
	uintptr_t raw = Serialize::serialize(&data);
	std::cout << raw << std::endl;

	std::cout << "\033[33m- Deserialized Data\033[37m" << std::endl;
	Data *data2 = Serialize::deserialize(raw);
	std::cout << "Data struct" 
				<< "\n\tint i:\t\t" << data.i 
				<< "\n\tfloat f:\t" << data.f 
				<< "\n\tdouble d:\t" << data.d 
				<< "\n\tchar c:\t\t" << data.c 
				<< "\n\tstring s:\t" << data.s 
				<< "\n\tAddress: \t" << &data
				<< std::endl;
	return (0);
}