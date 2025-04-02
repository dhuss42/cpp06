#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

/*--------------------------------------------------*/
/* Function generates random number between 0 and 2 */
/* 	- returns instance based on this number 		*/
/*--------------------------------------------------*/
Base * generate(void)
{
	srand(time(0));
	int num = rand() % 3;
	std::cout << "random number is: " << num << std::endl;
	if (num == 0)
		return (new A);
	else if (num == 1)
		return (new B);
	else
		return (new C);
}

/*----------------------------------------------------------------------------------*/
/* identifies type of Base using a pointer to the object							*/
/* 	- uses dynamic cast					 											*/
/*  	->	runtime type conversion used in polymorphic inheritance					*/
/* 		->	safely converts pointers/references between base and derived classes	*/
/* 		->	when used with pointers it can return nullptr							*/
/*	- use cases of dynamic cast														*/
/* 		->	When downcasting from a base class to a derived class					*/
/* 		->	When you don't know the exact type at compile time. 					*/
/*----------------------------------------------------------------------------------*/
void identify(Base* p)
{
	std::cout << "random istance is of type: ";
	if (dynamic_cast<A*>(p) == p)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) == p)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) == p)
		std::cout << "C" << std::endl;
}

/*----------------------------------------------------------------------------------*/
/* identifies type of Base using a reference to the object							*/
/* 	- uses dynamic cast					 											*/
/*		-> when used with references cannot return nullptr							*/
/*  - need to use try and catch														*/
/* 		->	 if conversion fails dynamic cast throws bad_cast						*/
/*----------------------------------------------------------------------------------*/
void identify(Base& p)
{
	std::cout << "random istance is of type: ";
	try 
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::bad_cast&){}
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::bad_cast&){}
	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::bad_cast&){}

}

int	main(void)
{
	Base* base;

	std::cout << "\033[33m- generating random object\033[37m" << std::endl;
	base = generate();
	std::cout << "\033[33m- identify using pointer to Base Object\033[37m" << std::endl;
	identify(base);
	std::cout << "\033[33m- identify using reference to Base Object\033[37m" << std::endl;
	identify(*base);
}
