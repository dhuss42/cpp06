/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:49:33 by dhuss             #+#    #+#             */
/*   Updated: 2025/04/03 08:49:34 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
