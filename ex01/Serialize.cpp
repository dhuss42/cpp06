/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuss <dhuss@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 08:49:33 by dhuss             #+#    #+#             */
/*   Updated: 2025/04/15 10:29:16 by dhuss            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

/*----------------------*/
/* Constructor			*/
/*----------------------*/
Serializer::Serializer()
{
}

/*----------------------*/
/* Copy Constructor		*/
/*----------------------*/
Serializer::Serializer(const Serializer& src)
{
	(void)	src;
}

/*----------------------*/
/* Assignment Operator	*/
/*----------------------*/
Serializer& Serializer::operator=(Serializer& other)
{
	(void)	other;
	return (*this);
}

/*----------------------*/
/* Destructor			*/
/*----------------------*/
Serializer::~Serializer()
{
}

//------------------public member methods------------------//

/*--------------------------*/
/* converts ptr to uintptr	*/
/*--------------------------*/
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/*--------------------------*/
/* converts uintptr to ptr	*/
/*--------------------------*/
Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
