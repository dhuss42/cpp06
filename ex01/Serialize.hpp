#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

#include "Data.hpp"

/*--------------------------------------------------------------------------------------*/
/* reinterpret_cast 																	*/
/* 	- conversion operator that allows converting one type to another unrelated type		*/
/*	- does not modify the underlying bit representation									*/
/*	- used mainly for pointer conversions												*/
/*--------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------*/
/* Serialization 																				*/
/* 	- process of converting a complex data structure that can be easily stored or transferred	*/
/*	- here it takes a the address of a pointer and converts it to an int representation			*/
/*----------------------------------------------------------------------------------------------*/

/*--------------------------------------------------*/
/* Deserialization 									*/
/* 	- inverse process of serialization				*/
/*	- pointer now refers to original data structure */
/*--------------------------------------------------*/

/*----------------------------------------------------------------------------------*/
/* uintptr_t																		*/
/* 	- designed for storing memory addresses in int form								*/
/*	- unsigned integer type that is guaranteed to be large enough to hold a pointer	*/
/* 	- automatically adapts to the architecture 32/64 bits 							*/
/*----------------------------------------------------------------------------------*/

class Serialize
{
	private:
		Serialize();
		Serialize(const Serialize& src);
		Serialize& operator=(Serialize& other);
		~Serialize();
	public:
		static	uintptr_t	serialize(Data* ptr);
		static	Data*		deserialize(uintptr_t raw);
};

#endif