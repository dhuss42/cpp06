#include "Serialize.hpp"

/*----------------------*/
/* Constructor			*/
/*----------------------*/
Serialize::Serialize()
{
}

/*----------------------*/
/* Copy Constructor		*/
/*----------------------*/
Serialize::Serialize(const Serialize& src)
{
	(void)	src;
}

/*----------------------*/
/* Assignment Operator	*/
/*----------------------*/
Serialize& Serialize::operator=(Serialize& other)
{
	(void)	other;
	return (*this);
}

/*----------------------*/
/* Destructor			*/
/*----------------------*/
Serialize::~Serialize()
{
}

//------------------public member methods------------------//

/*--------------------------*/
/* converts ptr to uintptr	*/
/*--------------------------*/
uintptr_t	Serialize::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/*--------------------------*/
/* converts uintptr to ptr	*/
/*--------------------------*/
Data*	Serialize::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
